package com.anuc.cloudJIT.entity.responnse;

import com.anuc.cloudJIT.entity.FuncInfo;
import lombok.Data;

import java.util.List;
@Data
public class SelectFunctionListResponse {
    List<FuncInfo> funcInfos;
}
