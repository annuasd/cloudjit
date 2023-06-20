package com.anuc.cloudJIT.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.util.List;

@TableName("module_info")
@Data
public class ModuleInfo {
    @TableId(value = "name", type = IdType.INPUT)
    String name;
    String description;
    Boolean correct;
    @TableField(exist = false)
    List<FuncInfo> funcInfos;

}
