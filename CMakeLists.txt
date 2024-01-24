cmake_minimum_required(VERSION 3.0.0)
project(SEMANA_3_ARBOLES VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(SEMANA_3_ARBOLES main.cpp avl.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
