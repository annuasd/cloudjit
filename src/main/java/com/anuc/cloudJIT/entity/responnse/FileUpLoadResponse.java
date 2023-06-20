package com.anuc.cloudJIT.entity.responnse;

import lombok.Data;

import java.util.ArrayList;

@Data
public class FileUpLoadResponse extends BaseResponse{
    ArrayList<String> fileContent;
}
