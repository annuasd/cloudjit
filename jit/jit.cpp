#include "jit.h"

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

template <class T>
T argTrans(char *s, std::string type) {
  std::cout << type << ": " << s << std::endl;
  if (type == "int")
    return atoi(s);
  else if (type == "float")
    return atof(s);
  else if (type == "long")
    return atol(s);
  else if (type == "double")
    return atof(s);
}

int main(int argc, char **argv) {
  ARGS_ASSIGNEXPAND
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();
  ModuleEngine eg("ir.ll");
  auto sum = new FunctionEngine<FUNC_TYPE>(STR2(FUNC_NAME));
  eg.FunctionEngineRegister(sum);
  auto func = sum->getFunctionAddr();
  std::cout << func(FUNC_ARGS_EXPAND) << std::endl;

  std::ofstream outputFile("../../result.txt");
  if (outputFile.is_open()) {
    outputFile << func(FUNC_ARGS_EXPAND);  // 写入信息到文件
    outputFile.close();
    std::cout << "写入成功！" << std::endl;
    return 0;
  } else {
    std::cout << "无法打开文件！" << std::endl;
    return 1;
  }
}
