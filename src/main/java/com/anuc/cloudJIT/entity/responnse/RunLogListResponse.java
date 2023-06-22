package com.anuc.cloudJIT.entity.responnse;

import com.anuc.cloudJIT.entity.RunLog;
import lombok.Data;

import java.util.List;
@Data
public class RunLogListResponse extends BaseResponse{
    private List<RunLog> runLogs;
}
