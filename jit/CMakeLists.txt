cmake_minimum_required(VERSION 3.2)
project(jitTest)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXE_DIR})

if(DEFINED EXE_NAME)
else()
    message(FATAL_ERROR "EXE_NAME IS NOT DEFINE!")
endif()

if(DEFINED FUNC_TYPE)
else()
    message(FATAL_ERROR "FUNC_TYPE IS NOT DEFINE!")
endif()
#llvm
find_package(LLVM REQUIRED)
message(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs  ${LLVM_TARGETS_TO_BUILD}  core support orcJIT passes)

add_compile_definitions(FUNC_TYPE=${FUNC_TYPE} ARG_TYPE=${ARG_TYPE} ARG_INDEX=${ARG_INDEX} FUNC_NAME=${EXE_NAME}) 
if(NULL_ARG)
    message("ddddddfffffffasdfsadfsadfdsaf")
    add_compile_definitions(NULL_ARG=${NULL_ARG})
endif()
add_executable(${EXE_NAME} jit.cpp jit.h autogen.h autogen.h)
target_link_libraries(${EXE_NAME} ${llvm_libs})