cmake_minimum_required(VERSION 2.8)
project(str)

include_directories(.)
LINK_DIRECTORIES(/usr/local/lib)

add_executable(is_brace_valid is_brace_valid.c)
#target_link_libraries(basic_test xx)

