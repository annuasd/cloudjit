package com.anuc.cloudJIT.entity;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
@TableName("function_info")
@Data
public class FuncInfo {
    @TableId(value = "id", type = IdType.AUTO)
    private Integer id;
    private String funcArgs;
    private String funcName;
    private String returnType;
    private String moduleName;
    private Boolean init;
}
