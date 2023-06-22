package com.anuc.cloudJIT.service;

import com.anuc.cloudJIT.dao.RunLogDao;
import com.anuc.cloudJIT.entity.RunLog;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.List;

@Service
public class RunLogService {
    private RunLogDao runLogDao;
    @Autowired
    public void setRunLogDao(RunLogDao runLogDao) {
        this.runLogDao = runLogDao;
    }
    public int createRunLog(RunLog runLog) {
        return runLogDao.insert(runLog);
    }

    public List<RunLog> selectRunLogByName(String name) {
        LambdaQueryWrapper<RunLog> lqw = new LambdaQueryWrapper<>();
        lqw.eq(RunLog::getName, name).orderByDesc(RunLog::getDate);
        return runLogDao.selectList(lqw);
    }

    public int deleteRunLogByName(String name) {
        LambdaQueryWrapper<RunLog> lqw = new LambdaQueryWrapper<>();
        lqw.eq(RunLog::getName, name);
        return runLogDao.delete(lqw);
    }

    public int deleteRunLogByDate(Date date) {
        LambdaQueryWrapper<RunLog> lqw = new LambdaQueryWrapper<>();
        lqw.eq(RunLog::getDate, date);
        return runLogDao.delete(lqw);
    }
}
