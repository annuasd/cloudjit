package com.anuc.cloudJIT.controller;
import com.alibaba.fastjson2.JSON;
import com.alibaba.fastjson2.JSONObject;
import com.anuc.cloudJIT.entity.FuncInfo;
import com.anuc.cloudJIT.entity.ModuleInfo;
import com.anuc.cloudJIT.entity.RunLog;
import com.anuc.cloudJIT.entity.responnse.*;
import com.anuc.cloudJIT.service.FuncInfoService;
import com.anuc.cloudJIT.service.ModuleInfoService;
import com.anuc.cloudJIT.service.RunLogService;
import org.apache.commons.io.FileUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Date;
import java.util.List;

@CrossOrigin
@RestController
public class FunctionController {
    private FuncInfoService funcInfoService;

    private RunLogService runLogService;

    @Autowired
    public void setFuncInfoService(FuncInfoService funcInfoService) {
        this.funcInfoService = funcInfoService;
    }
    @Autowired
    public void setRunLogService(RunLogService runLogService) { this.runLogService = runLogService; }

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
        ProcessBuilder irParser = new ProcessBuilder("./irparser", "../engines/"+ name +"/ir.ll", name);
        irParser.directory(new File(userDir + "/irParser"));
        Process parseProcess = irParser.start();
        exitCode = parseProcess.waitFor();
        if(exitCode != 0) {
            rep.setStatus(1);
            rep.setMessage("ir解析失败");
            return JSON.toJSONString(rep);
        }
        //调用c进程将文件编译完成，相关信息在管道文件中，jvm从管道文件中读取信息
        String filePath = userDir + "/module.json";
        String jsonStr = FileUtils.readFileToString(new File(filePath), StandardCharsets.UTF_8);
        JSONObject obj = JSON.parseObject(jsonStr);
        ModuleInfo moduleInfo = obj.toJavaObject(ModuleInfo.class);

        //将解析出的函数存入数据库
        funcInfoService.insertFuncInfos(moduleInfo.getFuncInfos());

        SelectOneModuleResponse mr = new SelectOneModuleResponse();
        mr.setModuleInfo(moduleInfo);
        return JSON.toJSONString(mr);
    }

    @PutMapping("/engine")
    String run(String moduleName, String funcName, String args) throws IOException, InterruptedException {
        BaseResponse rep = new BaseResponse();
        String userDir = System.getProperty("user.dir");
        String dir = userDir + "/engines/" + moduleName;
        File workFile = new File(dir);
        if(!workFile.exists()) {
            rep.setStatus(1);
            rep.setMessage("该文件不存在于目录中，删除失败");
            return JSON.toJSONString(rep);
        }
        ProcessBuilder engineRun = new ProcessBuilder();
        String exe = "./" + funcName;
        ArrayList<String> commands = new ArrayList<>();
        commands.add(exe);
        Arrays.asList(args.split(" ")).forEach((v) -> commands.add(v) );
        engineRun.directory(workFile);
        engineRun.command(commands);
        Process process = engineRun.start();
        int exitCode = process.waitFor();
        if(exitCode != 0) {
            rep.setStatus(1);
            rep.setMessage("运行失败");
            return JSONObject.toJSONString(rep);
        } else {
            String result = FileUtils.readFileToString(new File(userDir + "/result.txt"),
                    StandardCharsets.UTF_8);
            RunResultResponse rrep = new RunResultResponse();
            rrep.setResult(result);
            //插入日志中
            RunLog runLog = new RunLog();
            Date date = new Date(System.currentTimeMillis());
            runLog.setDate(date);
            runLog.setName(moduleName + '/'+ funcName);
            runLog.setResult(result);;
            runLog.setArgs(args);
            runLog.setModuleName(moduleName);
            runLogService.createRunLog(runLog);
            return JSON.toJSONString(rrep);
        }
    }
    @PostMapping("/engine")
    String engineInit(String moduleName, String funcName) throws IOException, InterruptedException {
        BaseResponse br = new BaseResponse();
        String userDir =  System.getProperty("user.dir");
        String workDir = userDir + "/jit";
        String targetDir = userDir + "/engines/" + moduleName;
        File workFile = new File(workDir);
        if(!workFile.exists()) {
            br.setStatus(1);
            br.setMessage("工作目录不存在!");
            return br.toString();
        }
        FuncInfo funcInfo = funcInfoService.selectFuncInfoByModule(moduleName, funcName).get(0);
        String args = funcInfo.getFuncArgs();
        String[] arg = args.split(",");
        String arg_type = "";
        String func_type = funcInfo.getReturnType();
        String arg_index = "";
        String null_arg = "false";
        int index = 1;
        for(String s: arg) {
            if(index == 1) func_type += '(';
            if(s.isEmpty()) break;
            s = s.trim();
            String type = s.split(" ")[0];
            func_type += type;
            arg_type += Integer.toString(index) + ',' +type;
            arg_index += Integer.toString(index);
            if(index != arg.length) {
                func_type += ',';
                arg_type += ',';
                arg_index += ',';
            }
            ++index;
        }
        if(index == 1) null_arg = "true";
        func_type += ')';
        System.out.println(func_type);
        System.out.println(arg_type);
        System.out.println(arg_index);
        //进程启动
        ProcessBuilder engineCompiler = new ProcessBuilder();
        engineCompiler.directory(workFile);
        if(index != 1)
            engineCompiler.command("./compiler.sh", targetDir, funcName, func_type, null_arg, arg_type, arg_index);
        else engineCompiler.command("./compiler.sh", targetDir, funcName, func_type, null_arg);
        System.out.println(engineCompiler.command());
        Process process = engineCompiler.start();
        int exitCode = process.waitFor();
        if(exitCode != 0) {
            br.setStatus(1);
            br.setMessage("引擎初始化错误");
        }
        funcInfoService.updateInitByName(funcName, true);
        return JSON.toJSONString(br);

    }

    @DeleteMapping("/engine/{mname}/{fname}")
    String deleteFunctionEngineByName(@PathVariable String mname, @PathVariable String fname) throws IOException {
        BaseResponse rep = new BaseResponse();
        String filePath =  System.getProperty("user.dir") +  "/engines/" + mname + "/" + fname;
        File dir = new File(filePath);
        if(!dir.exists()) {
            rep.setStatus(1);
            rep.setMessage("该文件不存在于目录中，删除失败");
            return JSON.toJSONString(rep);
        }
        FileUtils.forceDelete(dir);
        int i = funcInfoService.updateInitByName(fname, false);
        if(i == 0) {
            rep.setStatus(1);
            rep.setMessage("删除执行引擎时更新函数壮态失败");
            return JSON.toJSONString(rep);
        }
        return JSON.toJSONString(rep);
    }

    @GetMapping("/function/{mname}/{fname}")
    String selectFunctionByModuleNameAndFuncName(@PathVariable String mname, @PathVariable String fname) {
        List<FuncInfo> funcInfos = funcInfoService.selectFuncInfoByModule(mname, fname);
        SelectFunctionListResponse res = new SelectFunctionListResponse();
        res.setFuncInfos(funcInfos);
        return JSON.toJSONString(res);
    }
    @GetMapping("/function/{name}")
    String selectFunctionByName(@PathVariable String name) {
        List<FuncInfo> funcInfos = funcInfoService.selectFuncInfoByName(name);
        SelectFunctionListResponse res = new SelectFunctionListResponse();
        res.setFuncInfos(funcInfos);
        return JSON.toJSONString(res);
    }

    @GetMapping("/runlog/{mname}/{fname}")
    String selectRunlogByName(@PathVariable String mname, @PathVariable String fname) {
        RunLogListResponse rep = new RunLogListResponse();
        List<RunLog> runLogs = runLogService.selectRunLogByName(mname + '/' + fname);
        rep.setRunLogs(runLogs);
        return JSON.toJSONString(rep);
    }

    @DeleteMapping("/runlog/{mname}/{fname}")
    String deleteRunlogByName(@PathVariable String mname, @PathVariable String fname){
        BaseResponse rep = new BaseResponse();
        int i = runLogService.deleteRunLogByName(mname + '/' + fname);
        if(i == 0) {
            rep.setStatus(1);
            rep.setMessage("日志删除失败");
        }
        return JSON.toJSONString(rep);
    }

}
