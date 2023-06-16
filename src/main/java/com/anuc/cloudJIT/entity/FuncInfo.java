package com.anuc.cloudJIT.entity;

import com.alibaba.fastjson2.annotation.JSONField;

import java.util.Arrays;

public class FuncInfo {
    @JSONField(name = "arg_name")
    private String[] argName;
    @JSONField(name = "arg_type")
    private String[] argType;
    private String funcName;
    private String returnType;

    @Override
    public String toString() {
        return "FuncInfo{" +
                "argName=" + Arrays.toString(argName) +
                ", argType=" + Arrays.toString(argType) +
                ", funcName='" + funcName + '\'' +
                ", returnType='" + returnType + '\'' +
                '}';
    }

    public String[] getArgName() {
        return argName;
    }

    public void setArgName(String[] argName) {
        this.argName = argName;
    }

    public String[] getArgType() {
        return argType;
    }

    public void setArgType(String[] argType) {
        this.argType = argType;
    }

    public String getFuncName() {
        return funcName;
    }

    public void setFuncName(String funcName) {
        this.funcName = funcName;
    }

    public String getReturnType() {
        return returnType;
    }

    public void setReturnType(String returnType) {
        this.returnType = returnType;
    }

    public FuncInfo(String[] argName, String[] argType, String funcName, String returnType) {
        this.argName = argName;
        this.argType = argType;
        this.funcName = funcName;
        this.returnType = returnType;
    }
}
