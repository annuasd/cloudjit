package com.anuc.cloudJIT.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

@TableName("module_info")
@Data
public class ModuleInfo {
    @TableId(value = "name", type = IdType.INPUT)
    String name;
}
