package com.anuc.cloudJIT.controller;

import com.alibaba.fastjson2.JSON;
import com.anuc.cloudJIT.entity.ModuleInfo;
import com.anuc.cloudJIT.entity.responnse.BaseResponse;
import com.anuc.cloudJIT.entity.responnse.SelectModuleListResponse;
import com.anuc.cloudJIT.entity.responnse.SelectOneModuleResponse;
import com.anuc.cloudJIT.service.ModuleInfoService;
import jakarta.servlet.http.HttpServletRequest;
import org.apache.commons.io.FileUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.io.*;

@RestController
public class ModuleController {
    private ModuleInfoService moduleInfoService;
    @GetMapping("/userDir")
    String userDir() {
        return System.getProperty("user.dir");
    }
    @GetMapping("/")
    String home() {
        return  System.getProperty("user.home");
    }
    @Autowired
    public void setModuleInfoService(ModuleInfoService moduleInfoService) {
        this.moduleInfoService = moduleInfoService;
    }
    @PostMapping("/module")
    String uploadFile(MultipartFile f, HttpServletRequest request) throws IOException {
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
        moduleInfoService.insertModuleInfo(info);
        rep.setMessage("上传成功");
        return JSON.toJSONString(rep);
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
        SelectModuleListResponse rep = moduleInfoService.selectModuleInfoAll();
        return JSON.toJSONString(rep);
    }

    @GetMapping("/module/{name}")
    String getModuleByName(@PathVariable String name) {
        SelectOneModuleResponse srep = moduleInfoService.selectModuleInfoByName(name);
        if(srep == null) {
            return JSON.toJSONString(new BaseResponse());
        }
        return JSON.toJSONString(srep);
    }

}
