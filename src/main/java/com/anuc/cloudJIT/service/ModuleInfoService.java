package com.anuc.cloudJIT.service;

import com.anuc.cloudJIT.dao.ModuleInfoDao;
import com.anuc.cloudJIT.entity.FuncInfo;
import com.anuc.cloudJIT.entity.ModuleInfo;
import com.anuc.cloudJIT.entity.responnse.SelectModuleListResponse;
import com.anuc.cloudJIT.entity.responnse.SelectOneModuleResponse;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class ModuleInfoService {
    private ModuleInfoDao moduleInfoDao;
    @Autowired
    public void setModuleInfoDao(ModuleInfoDao moduleInfoDao) {
        this.moduleInfoDao = moduleInfoDao;
    }

    private FuncInfoService funcInfoService;
    @Autowired
    public void setFuncInfoService(FuncInfoService funcInfoService) { this.funcInfoService = funcInfoService; }

    public int createModuleInfo(ModuleInfo moduleInfo) {
        return moduleInfoDao.insert(moduleInfo);
    }

    public int insertModuleInfo(ModuleInfo moduleInfo) {
       return moduleInfoDao.insert(moduleInfo);
    }

    public SelectOneModuleResponse selectModuleInfoByName(String name) {
        LambdaQueryWrapper<ModuleInfo> lqw = new LambdaQueryWrapper<>();
        lqw.eq(ModuleInfo::getName, name);
        if(moduleInfoDao.selectOne(lqw) == null) {
            return null;
        }
        List<FuncInfo> funcInfos =  funcInfoService.selectFuncInfoByModule(name);
        SelectOneModuleResponse msr = new SelectOneModuleResponse();
        msr.setFuncInfos(funcInfos);
        msr.setName(name);
        return msr;
    }

    public SelectModuleListResponse selectModuleInfoAll() {
        List<ModuleInfo> moduleInfos = moduleInfoDao.selectList(null);
        ArrayList<SelectOneModuleResponse> arrayList = new ArrayList<>();
        for(ModuleInfo moduleInfo: moduleInfos) {
            SelectOneModuleResponse msr = new SelectOneModuleResponse();
            List<FuncInfo> funcInfos =  funcInfoService.selectFuncInfoByModule(moduleInfo.getName());
            msr.setName(moduleInfo.getName());
            msr.setFuncInfos(funcInfos);
            arrayList.add(msr);
        }
        SelectModuleListResponse smlr = new SelectModuleListResponse();
        smlr.setModuleResponses(arrayList);
        return smlr;
    }

    public int deleteModuleInfoByName(String name) {
        LambdaQueryWrapper<ModuleInfo> lqw = new LambdaQueryWrapper<>();
        lqw.eq(ModuleInfo::getName, name);
        return moduleInfoDao.delete(lqw);
    }





}
