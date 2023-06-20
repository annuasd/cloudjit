package com.anuc.cloudJIT.service;

import com.anuc.cloudJIT.dao.ModuleInfoDao;
import com.anuc.cloudJIT.entity.FuncInfo;
import com.anuc.cloudJIT.entity.ModuleInfo;
import com.anuc.cloudJIT.entity.responnse.SelectModuleListResponse;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
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

    public ModuleInfo selectModuleInfoByName(String name) {
        LambdaQueryWrapper<ModuleInfo> lqw = new LambdaQueryWrapper<>();
        lqw.eq(ModuleInfo::getName, name);
        ModuleInfo moduleInfo = moduleInfoDao.selectOne(lqw);
        if(moduleInfo == null) {
            return null;
        }
        List<FuncInfo> funcInfos =  funcInfoService.selectFuncInfoByModule(name);
        moduleInfo.setFuncInfos(funcInfos);
        return moduleInfo;
    }

    public  List<ModuleInfo> selectModuleInfoAll() {
        List<ModuleInfo> moduleInfos = moduleInfoDao.selectList(null);
        ArrayList<ModuleInfo> arrayList = new ArrayList<>();
        for(ModuleInfo moduleInfo: moduleInfos) {
            List<FuncInfo> funcInfos =  funcInfoService.selectFuncInfoByModule(moduleInfo.getName());
            moduleInfo.setFuncInfos(funcInfos);
            arrayList.add(moduleInfo);
        }
        SelectModuleListResponse smlr = new SelectModuleListResponse();
        smlr.setModuleInfos(arrayList);
        return moduleInfos;
    }

    public int deleteModuleInfoByName(String name) {
        LambdaQueryWrapper<ModuleInfo> lqw = new LambdaQueryWrapper<>();
        lqw.eq(ModuleInfo::getName, name);
        return moduleInfoDao.delete(lqw);
    }

    public int setModuleCorrectByName(String name, boolean j) {
        LambdaUpdateWrapper<ModuleInfo> luw = new LambdaUpdateWrapper<>();
        luw.eq(ModuleInfo::getName, name).set(ModuleInfo::getCorrect, j);
        return moduleInfoDao.update(null, luw);
    }
    public int updateModuleDescriptionByName(String name, String description) {
        LambdaUpdateWrapper<ModuleInfo> luw = new LambdaUpdateWrapper<>();
        luw.eq(ModuleInfo::getName, name).set(ModuleInfo::getDescription, description);
        return moduleInfoDao.update(null, luw);
    }


}
