cmake_minimum_required (VERSION 3.5)

project (HelloWrold)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_LAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
#set (bin_dir "${PROJECT_SOURCE_DIR}/bin/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (HelloWorld ${source_files})
