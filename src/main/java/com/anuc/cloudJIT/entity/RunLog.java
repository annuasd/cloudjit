package com.anuc.cloudJIT.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.Date;

@TableName("run_log")
@Data
public class RunLog {
    private Date date;
    private String name;
    private String result;
    private String args;
    private String moduleName;
    private String input;
    private String output;
}
