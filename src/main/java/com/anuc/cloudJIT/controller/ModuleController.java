package com.anuc.cloudJIT.controller;

import com.alibaba.fastjson2.JSON;
import com.anuc.cloudJIT.entity.ModuleInfo;
import com.anuc.cloudJIT.entity.responnse.BaseResponse;
import com.anuc.cloudJIT.entity.responnse.FileUpLoadResponse;
import com.anuc.cloudJIT.entity.responnse.SelectModuleListResponse;
import com.anuc.cloudJIT.entity.responnse.SelectOneModuleResponse;
import com.anuc.cloudJIT.service.ModuleInfoService;
import com.fasterxml.jackson.databind.ser.Serializers;
import jakarta.servlet.http.HttpServletRequest;
import org.apache.commons.io.FileUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.io.*;
import java.util.ArrayList;

@CrossOrigin
@RestController
public class ModuleController {
    private ModuleInfoService moduleInfoService;
    @Autowired
    public void setModuleInfoService(ModuleInfoService moduleInfoService) {
        this.moduleInfoService = moduleInfoService;
    }


    @GetMapping("/userDir")
    String userDir() {
        return System.getProperty("user.dir");
    }
    @GetMapping("/")
    String home() {
        return  System.getProperty("user.home");
    }

    @PostMapping("/module")
    String uploadFile(MultipartFile f, String description, HttpServletRequest request) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(f.getInputStream()));
        FileUpLoadResponse fulr = new FileUpLoadResponse();
        BaseResponse rep = new BaseResponse();
        String userDir = System.getProperty("user.dir");
        String fileName = f.getOriginalFilename();
        File dir = new File(userDir + "/engines/" + fileName.split("\\.")[0]);
        if(dir.exists()) {
            rep.setStatus(1);
            rep.setMessage("该文件已经存在于目录中，上传失败");
            return JSON.toJSONString(rep);
        }
        if(moduleInfoService.selectModuleInfoByName(fileName.split("\\.")[0]) != null) {
            rep.setStatus(1);
            rep.setMessage("该文件已经存在于数据库中，发生错误");
            return JSON.toJSONString(rep);
        }
        dir.mkdir();
        File file = new File(dir + "/" + fileName);
        f.transferTo(file);
        System.out.println(file.getPath());
        ModuleInfo info = new ModuleInfo();
        info.setName(fileName.split("\\.")[0]);
        info.setDescription(description);
        moduleInfoService.insertModuleInfo(info);
        fulr.setMessage("上传成功");
        ArrayList<String> content = new ArrayList<>();
        String line;
        while((line = bufferedReader.readLine()) != null) {
            content.add(line);
        }
        fulr.setFileContent(content);
        fulr.setDescription(description);
        return JSON.toJSONString(fulr);
    }



    @DeleteMapping("/module/{name}")
    String delete(@PathVariable String name) throws IOException {
        BaseResponse rep = new BaseResponse();
        int row = moduleInfoService.deleteModuleInfoByName(name);
        if(row == 0) {
            rep.setStatus(1);
            rep.setMessage("从数据库中删除模块失败");
        }
        String filePath =  System.getProperty("user.dir") +  "/engines/" + name;
        File dir = new File(filePath);
        if(!dir.exists()) {
            rep.setStatus(1);
            rep.setMessage("该文件不存在于目录中，删除失败");
            return JSON.toJSONString(rep);
        }
        FileUtils.forceDelete(dir);
        return JSON.toJSONString(rep);
    }

    @GetMapping("/module")
    String getAllModule() {
        SelectModuleListResponse rep = new SelectModuleListResponse();
        rep.setModuleInfos(moduleInfoService.selectModuleInfoAll());
        return JSON.toJSONString(rep);
    }

    @GetMapping("/module/{name}")
    String getModuleByName(@PathVariable String name) {
        SelectOneModuleResponse srep = new SelectOneModuleResponse();
        srep.setModuleInfo(moduleInfoService.selectModuleInfoByName(name));
        if(srep == null) {
            return JSON.toJSONString(new BaseResponse());
        }
        return JSON.toJSONString(srep);
    }

    @PutMapping("/module/{name}")
    String updateModuleByName(String description, @PathVariable String name) {
        BaseResponse br = new BaseResponse();
        int i = moduleInfoService.updateModuleDescriptionByName(name, description);
        if(i != 0) br.setMessage("更新成功");
        else {
            br.setStatus(1);
            br.setMessage("更新失败");
        }
        return JSON.toJSONString(br);
    }

    @GetMapping("file/{name}")
    String getFile(@PathVariable String name) throws IOException {
        FileUpLoadResponse fulr = new FileUpLoadResponse();
        BaseResponse rep = new BaseResponse();
        String filePath =  System.getProperty("user.dir") +  "/engines/" + name + "/" + name +".c";
        File dir = new File(filePath);
        if(!dir.exists()) {
            rep.setStatus(1);
            rep.setMessage("该文件不存在于目录中");
            return JSON.toJSONString(rep);
        }
        BufferedReader reader = new BufferedReader(new FileReader(dir));
        String line;
        ArrayList<String> content = new ArrayList<>();
        while ((line = reader.readLine()) != null) {
            System.out.println(line);
            content.add(line);
        }
        ModuleInfo moduleInfo = moduleInfoService.selectModuleInfoByName(name);
        fulr.setFileContent(content);
        fulr.setDescription(moduleInfo.getDescription());
        return JSON.toJSONString(fulr);
    }

}
