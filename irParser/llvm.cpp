#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ejson/parser.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SourceMgr.h"

using namespace std;
using namespace ejson;

struct FuncInfo{
    string func_name;
    string module_name;
    string return_type;
    vector<string> arg_type;
    vector<string> arg_name;
};

struct ModuleInfo {
    string module_name;
    vector<FuncInfo> func_infos;
};

AUTO_GEN_NON_INTRUSIVE(FuncInfo, func_name, module_name, return_type, arg_type, arg_name)
AUTO_GEN_NON_INTRUSIVE(ModuleInfo, module_name, func_infos)

ENABLE_JSON_COUT(ModuleInfo, FuncInfo)

string get_type_name(llvm::Type *ty) {
    if(ty->isIntegerTy(32)) return "int";
    else if(ty->isIntegerTy(64)) return "long";
    else if(ty->isFloatTy()) return "float";
    else if(ty->isDoubleTy()) return "double";
    return "unknown_type!";
}

int main(int argc , char* argv[]) {
    string filename = argv[1];
    cout << argv[1] << endl;
    auto context = make_unique<llvm::LLVMContext>();
    llvm::SMDiagnostic error;
    error_code ec;
    unique_ptr<llvm::Module> irModule = parseIRFile(filename, error, *context);
    ModuleInfo module_info;
    string mname = irModule->getName().str();
    module_info.module_name = mname;
    for(auto &func: *irModule) {
        FuncInfo func_info;
        func_info.func_name = func.getName().str();
        func_info.module_name = mname;
        llvm::Type *return_type = func.getReturnType();
        func_info.return_type = get_type_name(return_type);
        for(auto arg = func.arg_begin(); arg != func.arg_end(); ++arg) {
            llvm::Type *ty = arg->getType();
            string arg_name = arg->getName().str();
            string arg_type = get_type_name(ty);
            func_info.arg_name.push_back(arg_name);
            func_info.arg_type.push_back(arg_type);
        }
        module_info.func_infos.push_back(func_info);
    }
    std::ofstream outputFile("../module.json"); 
    if (outputFile.is_open()) {
        outputFile  << Parser::ToJSON(module_info, 1); // 写入信息到文件
        outputFile.close(); 
        std::cout << "写入成功！" << std::endl;
    } else {
        std::cout << "无法打开文件！" << std::endl;
    }

}
