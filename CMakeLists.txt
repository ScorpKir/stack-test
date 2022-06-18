cmake_minimum_required(VERSION 3.22)
project(stack_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack_test main.cpp errors.h fill.h convert.h)

install(TARGETS stack_test DESTINATION bin)
