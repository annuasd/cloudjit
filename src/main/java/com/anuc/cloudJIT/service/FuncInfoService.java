package com.anuc.cloudJIT.service;

import com.anuc.cloudJIT.dao.FuncInfoDao;
import com.anuc.cloudJIT.entity.FuncInfo;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class FuncInfoService {
    private FuncInfoDao funcInfoDao;
    @Autowired
    public void setFuncInfoDao(FuncInfoDao funcInfoDao) { this.funcInfoDao = funcInfoDao; }

    public List<FuncInfo> selectFuncInfoByModule(String moduleName) {
        LambdaQueryWrapper<FuncInfo> lqw = new LambdaQueryWrapper<>();
        lqw.eq(FuncInfo::getModuleName, moduleName);
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
