cmake_minimum_required(VERSION 3.2)
project(jitParser)
set(CMAKE_CXX_STANDARD 17)
#SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

#ejson
add_subdirectory(ejson4cpp)

#llvm
find_package(LLVM REQUIRED)
message(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs  ${LLVM_TARGETS_TO_BUILD}  core support orcJIT passes)

add_executable(irparser llvm.cpp)
target_link_libraries(irparser ${llvm_libs} ejson)