package com.anuc.cloudJIT.controller;

import com.alibaba.fastjson2.JSON;
import com.alibaba.fastjson2.JSONObject;
import com.alibaba.fastjson2.annotation.JSONField;
import com.anuc.cloudJIT.entity.FuncInfo;
import jakarta.servlet.http.HttpServletRequest;
import org.apache.commons.io.FileUtils;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;

@RestController
public class ModuleController {
    @GetMapping("/")
    String home() {
        return  System.getProperty("user.home");
    }

    @PostMapping("/upload")
    String uploadFile(MultipartFile f, HttpServletRequest request) throws IOException {
        String userDir = System.getProperty("user.dir");
        String fileName = f.getOriginalFilename();
        File dir = new File(userDir + "/engines/" + fileName.split("\\.")[0]);
        if(dir.exists()) {
           return "该文件已经存在，上传失败！";
        }
        dir.mkdir();
        File file = new File(dir + "/" + fileName);
        f.transferTo(file);
        System.out.println(file.getPath());
        return "上传成功！";
    }

    @PostMapping("/parse")
    String parse(String name) throws IOException, InterruptedException {
        class Module {
            @JSONField(name = "module_name")
            String moduleName;
            @JSONField(name = "func_infos")
            ArrayList<FuncInfo> funcInfos;
            public String getModuleName() {
                return moduleName;
            }
            public void setModuleName(String moduleName) {
                this.moduleName = moduleName;
            }
            public ArrayList<FuncInfo> getFuncInfos() {
                return funcInfos;
            }
            public void setFuncInfos(ArrayList<FuncInfo> funcInfos) {
                this.funcInfos = funcInfos;
            }

            @Override
            public String toString() {
                return "Module{" +
                        "moduleName='" + moduleName + '\'' +
                        ", funcInfos=" + funcInfos +
                        '}';
            }
        }
        String userDir =  System.getProperty("user.dir");
        String enginesDir = userDir + "/engines/" + name;
        File dir = new File(enginesDir);
        if(!dir.exists()) {
            return "源文件不存在，无法解析！";
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
        if(exitCode != 0)  return "文件编译失败";
        ProcessBuilder irParser = new ProcessBuilder("./irparser", "../engines/"+ name +"/ir.ll");
        irParser.directory(new File(userDir + "/irParser"));
        Process parseProcess = irParser.start();
        exitCode = parseProcess.waitFor();
        if(exitCode != 0) return "解析失败";
        String filePath = userDir + "/module.json";
        String jsonStr = FileUtils.readFileToString(new File(filePath), StandardCharsets.UTF_8);
        JSONObject jsonObject = JSON.parseObject(jsonStr);
        Module module = jsonObject.toJavaObject(Module.class);
        System.out.println(module.toString());
        return jsonObject.toString();
    }


    @PostMapping("/run")
    //String moduleName, @RequestBody FuncInfo funcInfo
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


}
