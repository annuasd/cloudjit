package com.anuc.cloudJIT.controller;
import com.alibaba.fastjson2.JSON;
import com.alibaba.fastjson2.JSONObject;
import com.anuc.cloudJIT.entity.ArgInfo;
import com.anuc.cloudJIT.entity.FuncInfo;
import com.anuc.cloudJIT.entity.responnse.BaseResponse;
import com.anuc.cloudJIT.entity.responnse.SelectOneModuleResponse;
import com.anuc.cloudJIT.service.FuncInfoService;
import org.apache.commons.io.FileUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

@CrossOrigin
@RestController
public class FunctionController {
    private FuncInfoService funcInfoService;
    @Autowired
    public void setFuncInfoService(FuncInfoService funcInfoService) {
        this.funcInfoService = funcInfoService;
    }
    @PostMapping("/function")
    String parse(String name) throws IOException, InterruptedException {
        BaseResponse rep = new BaseResponse();
        String userDir =  System.getProperty("user.dir");
        String enginesDir = userDir + "/engines/" + name;
        File dir = new File(enginesDir);
        if(!dir.exists()) {
            rep.setStatus(1);
            rep.setMessage("源文件不存在，无法解析");
            return rep.toString();
        }
        String sourceFileName = name + ".c";
        ProcessBuilder clang = new ProcessBuilder("clang", "-S", "-emit-llvm",
                "-fno-discard-value-names",
                "-o", "ir.ll", sourceFileName);
        clang.directory(dir);
        Process clangProcess = clang.start();
        InputStream inputStream = clangProcess.getInputStream();
        BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
        int exitCode = clangProcess.waitFor();
        if(exitCode != 0) {
            rep.setStatus(1);
            rep.setMessage("文件编译失败");
            return JSON.toJSONString(rep);
        }
        ProcessBuilder irParser = new ProcessBuilder("./irparser", "../engines/"+ name +"/ir.ll");
        irParser.directory(new File(userDir + "/irParser"));
        Process parseProcess = irParser.start();
        exitCode = parseProcess.waitFor();
        if(exitCode != 0) {
            rep.setStatus(1);
            rep.setMessage("解析失败");
            return JSON.toJSONString(rep);
        }
        String filePath = userDir + "/module.json";
        String jsonStr = FileUtils.readFileToString(new File(filePath), StandardCharsets.UTF_8);
        JSONObject jsonObject = JSON.parseObject(jsonStr);
        FuncInfo[] funcInfos = jsonObject.getObject("func_infos",  FuncInfo[].class);
        String[] pathName = jsonObject.getObject("module_name", String.class).split("/");
        String moduleName = pathName[pathName.length - 2];
        jsonObject.put("module_name", moduleName);
        for(FuncInfo info: funcInfos) {
            String args = new String();
            ArrayList<ArgInfo> argInfos = new ArrayList<>();
            for(int i = 0; i < info.getArgName().length; ++i) {
                args = args + info.getArgType()[i] + " " + info.getArgName()[i];
                if(i != info.getArgName().length - 1) args = args + ", ";
                ArgInfo argInfo = new ArgInfo();
                argInfo.setType(info.getArgType()[i]);
                argInfo.setName(info.getArgName()[i]);
                argInfos.add(argInfo);
            }
            info.setFuncArgs(args);
            info.setArgs(argInfos.toArray(new ArgInfo[info.getArgName().length]));
            info.setModuleName(moduleName);
            funcInfoService.insertFuncInfo(info);
        }
        SelectOneModuleResponse mr = new SelectOneModuleResponse();
        mr.setName(moduleName);
        mr.setFuncInfos(Arrays.asList(funcInfos));
        jsonObject.put("func_infos", funcInfos);
        return JSON.toJSONString(mr);
    }
    @PutMapping("/function")
    String run(String moduleName, String funcName, String funcType, String funcArgs) throws IOException, InterruptedException {
        String userDir = System.getProperty("user.dir");
        String dir = userDir + "/jit";
        File workFile = new File(dir);
        ProcessBuilder engineCompiler = new ProcessBuilder();
        engineCompiler.directory(workFile);
        engineCompiler.command("./compiler.sh", "exe", funcType, funcArgs);
        Process process1 = engineCompiler.start();
        int exitCode = process1.waitFor();
        if(exitCode == 0) {
            String sourceFilePath =  "../engines/" + moduleName + "/ir.ll";
            ProcessBuilder functionRun = new ProcessBuilder();
            functionRun.directory(workFile);
            System.out.println(sourceFilePath);
            functionRun.command("./exe",  funcName, sourceFilePath);
            Process process2 = functionRun.start();
            exitCode = process2.waitFor();
            String result = FileUtils.readFileToString(new File(userDir + "/result.txt"),
                    StandardCharsets.UTF_8);
            return result;
        }
        else return "运行失败！";
    }

    @GetMapping("/function/{mname}/{fname}")
    String selectAllFunction(@PathVariable String mname, @PathVariable String fname) {
        List<FuncInfo> funcInfos = funcInfoService.selectFuncInfoByModule(mname, fname);
        SelectOneModuleResponse res = new SelectOneModuleResponse();
        res.setFuncInfos(funcInfos);
        return JSON.toJSONString(res);
    }
    @GetMapping("/function/{name}")
    String selectFunctionByName(@PathVariable String name) {
        List<FuncInfo> funcInfos = funcInfoService.selectFuncInfoByName(name);
        SelectOneModuleResponse res = new SelectOneModuleResponse();
        res.setFuncInfos(funcInfos);
        return JSON.toJSONString(res);
    }



}
