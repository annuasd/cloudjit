#include "jit.h"

#ifndef FUNC_TYPE
#define FUNC_TYPE void()
#endif
#ifndef FUNC_PARAM
#define FUNC_PARAM 0
#endif

int main(int argc, char** argv) {
    std::string funcName = argv[1];
    std::string fileName = argv[2];
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    ModuleEngine eg(fileName);
    auto sum = new FunctionEngine<FUNC_TYPE>(funcName);
    eg.FunctionEngineRegister(sum);
    auto func = sum->getFunctionAddr();
    std::ofstream outputFile("../result.txt"); 
    if (outputFile.is_open()) {
        outputFile  << func(FUNC_PARAM); // 写入信息到文件
        outputFile.close(); 
        std::cout << "写入成功！" << std::endl;
        return 0;
    } else {
        std::cout << "无法打开文件！" << std::endl;
        return 1;
    }
    //std::cout << func(FUNC_PARAM) << std::endl;
}
