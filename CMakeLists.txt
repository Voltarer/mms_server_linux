cmake_minimum_required(VERSION 3.10)
project(mms_server_linux)

set(CMAKE_C_STANDARD 11)

set(LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/libiec61850)

include_directories(${LIB_DIR}/src/iec61850/inc)
include_directories(${LIB_DIR}/src/mms/inc)
include_directories(${LIB_DIR}/src/common/inc)
include_directories(${LIB_DIR}/hal/inc)
include_directories(${LIB_DIR}/hal/api)          
include_directories(${LIB_DIR}/src/logging)       

add_executable(mms_server src/main.c src/static_model.c)

target_link_libraries(mms_server ${LIB_DIR}/build/libiec61850.a pthread rt)