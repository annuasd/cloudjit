#include "jit.h"
#include "sstream"
#include "autogen.h"
#ifndef FUNC_TYPE
#define FUNC_TYPE int(int, float, int)
#endif

#ifndef ARG_TYPE
#define ARG_TYPE 1, int, 2, float, 3, float
#endif

#define CONTACT_WITH_ARG(x) arg##x

#ifndef ARG_INDEX
#define ARG_INDEX 1, 2, 3
#endif

#ifndef FUNC_NAME
#define FUNC_NAME sum
#endif

#define STR(X) #X
#define STR2(X) STR(X)

#ifdef NULL_ARG
#define FUNC_ARGS_EXPAND
#define ARGS_ASSIGNEXPAND
#else
#define FUNC_ARGS_EXPAND CJIT_PASTE(CONTACT_WITH_ARG, ARG_INDEX)
#define ARGS_ASSIGNEXPAND CJIT_ARG2_PASTE(argTrans, ARG_TYPE)
#endif

std::vector<std::string> split(const std::string& str, char delim) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

template <class T>
T argTrans(char *s, std::string type) {
  // std::cout << type << ": " << s << std::endl;
  if (type == "int")
    return atoi(s);
  else if (type == "float")
    return atof(s);
  else if (type == "long")
    return atol(s);
  else if (type == "double")
    return atof(s);
}
//读入参数，最后一个参数为连接文件，用逗号隔开 例如a,fadsf,fsadfsa
//如果没有参数，读入一个单独的逗号 ,
int main(int argc, char **argv) {
  ARGS_ASSIGNEXPAND
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();
  ModuleEngine eg("ir.ll");

  //处理链接参数
  std::string str = argv[argc-1];
  std::vector<std::string> objectFiles = split(str, ',');
  eg.addObjdecFile(objectFiles);
  auto sum = new FunctionEngine<FUNC_TYPE>(STR2(FUNC_NAME));
  eg.FunctionEngineRegister(sum);
  auto func = sum->getFunctionAddr();
  std::ofstream outputFile("../../result.txt");
  if (outputFile.is_open()) {
    outputFile << func(FUNC_ARGS_EXPAND);  // 写入信息到文件
    outputFile.close();
    return 0;
  } else {
    return 1;
  }
}
