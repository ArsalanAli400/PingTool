cmake_minimum_required(VERSION 3.10)
project(nettool)

set(CMAKE_CXX_STANDARD 14)
set(UHD_LIB_NAME libNettools.a)
set(Lib_path nettoolslib/static)
set(Header_path nettoolslib/include)


## Linking Directories
link_directories(${Lib_path})
include_directories(${Header_path})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${UHD_LIB_NAME})
