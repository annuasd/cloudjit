package com.anuc.cloudJIT.entity.responnse;

import lombok.Data;

@Data
public class BaseResponse {
    protected int status = 0;
    protected String message = "成功";

}
