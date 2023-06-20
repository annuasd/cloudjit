package com.anuc.cloudJIT.entity.responnse;

import com.anuc.cloudJIT.entity.FuncInfo;
import com.anuc.cloudJIT.entity.ModuleInfo;
import lombok.Data;

import java.util.List;
@Data
public class SelectModuleListResponse extends BaseResponse  {
    List<ModuleInfo> moduleInfos;
}
