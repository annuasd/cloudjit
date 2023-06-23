package com.anuc.cloudJIT.entity.responnse;

import lombok.Data;

import java.util.ArrayList;

@Data
public class RunResultResponse extends BaseResponse{
    String result;
    ArrayList<String> output;
}
