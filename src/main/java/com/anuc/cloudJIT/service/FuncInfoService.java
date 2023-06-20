package com.anuc.cloudJIT.service;

import com.anuc.cloudJIT.dao.FuncInfoDao;
import com.anuc.cloudJIT.entity.FuncInfo;
import com.anuc.cloudJIT.entity.ModuleInfo;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.LambdaUpdateWrapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class FuncInfoService {
    private FuncInfoDao funcInfoDao;
    @Autowired
    public void setFuncInfoDao(FuncInfoDao funcInfoDao) { this.funcInfoDao = funcInfoDao; }

    public int updateInitByName(String name, Boolean init) {
        LambdaUpdateWrapper<FuncInfo> luw = new LambdaUpdateWrapper<>();
        luw.eq(FuncInfo::getFuncName, name).set(FuncInfo::getInit, init);
        return funcInfoDao.update(null, luw);
    }

    public List<FuncInfo> selectFuncInfoByModule(String moduleName, String funcName) {
        LambdaQueryWrapper<FuncInfo> lqw = new LambdaQueryWrapper<>();
        lqw.eq(FuncInfo::getModuleName, moduleName).eq(FuncInfo::getFuncName, funcName);
        List<FuncInfo> result = funcInfoDao.selectList(lqw);
        return result;
    }

    public List<FuncInfo> selectFuncInfoByModule(String moduleName) {
        LambdaQueryWrapper<FuncInfo> lqw = new LambdaQueryWrapper<>();
        lqw.eq(FuncInfo::getModuleName, moduleName);
        List<FuncInfo> result = funcInfoDao.selectList(lqw);
        return result;
    }

    public List<FuncInfo> selectFuncInfoByName(String name) {
        LambdaQueryWrapper<FuncInfo> lqw = new LambdaQueryWrapper<>();
        lqw.eq(FuncInfo::getFuncName, name);
        List<FuncInfo> result = funcInfoDao.selectList(lqw);
        return result;
    }

    public int insertFuncInfos(List<FuncInfo> funcInfos) {
        for(FuncInfo funcInfo: funcInfos) {
            funcInfoDao.insert(funcInfo);
        }
        return 0;
    }


    public int insertFuncInfo(FuncInfo funcInfo) {
        return funcInfoDao.insert(funcInfo);
    }
}
