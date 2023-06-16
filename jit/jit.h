#include <memory.h>
#include <string>
#include <iostream>
#include <tuple>
#include <fstream>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/ExecutionEngine/Orc/Core.h"
#include "llvm/ExecutionEngine/Orc/LLJIT.h"
#include "llvm/Support/TargetSelect.h"
#include <map>
#include <any>
using namespace llvm;
using namespace orc;
class ModuleEngine;
struct FunctionEngineBase {
    ModuleEngine *me;
    std::string name;
    FunctionEngineBase(std::string name): name(name) {}
};


struct ModuleEngine {
    std::unique_ptr<LLLazyJIT> engine;
    ExitOnError exitOnError;
    std::map<std::string, std::any> functionEngines;
    ModuleEngine(std::string fileName) {
        auto context = std::make_unique<LLVMContext>();
        SMDiagnostic error;
        std::error_code ec;
        std::unique_ptr<Module> module = parseIRFile(fileName, error, *context);
        module->print(outs(), nullptr);
        ThreadSafeModule irModule = ThreadSafeModule(std::move(module), std::move(context));
        engine = exitOnError(LLLazyJITBuilder().create());
        exitOnError(engine->addIRModule(std::move(irModule)));
    }
    void FunctionEngineRegister(FunctionEngineBase *feg, FunctionEngineBase *rest...) {
        FunctionEngineRegister(feg);
        FunctionEngineRegister(feg);

    }
    void FunctionEngineRegister(FunctionEngineBase *feg) {
        functionEngines.insert({feg->name, std::any(feg) });
        feg->me = this;
    }

    std::any GetFunctionEngine(std::string name) {
        auto it = functionEngines.find(name);
        if(it == functionEngines.end()) return std::any{};
        return it->second;
    }

};

template <class FunctionType>
struct FunctionEngine: public FunctionEngineBase{
    FunctionEngine(std::string name): FunctionEngineBase(name) {}
    FunctionType *getFunctionAddr() {
        ExecutorAddr addr = me->exitOnError(me->engine->lookup(name));
        FunctionType* func  = addr.toPtr<FunctionType>();
        return func;
    }
};


