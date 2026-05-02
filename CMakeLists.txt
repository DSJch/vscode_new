cmake_minimum_required(VERSION 3.15)
project(SortAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 源码目录
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(ALGO_DIR ${SRC_DIR}/algorithms)
set(COMMON_DIR ${SRC_DIR}/common)
set(TEST_DIR ${SRC_DIR}/test)

# 源文件收集
file(GLOB ALGO_SRC ${ALGO_DIR}/*.cpp)
file(GLOB COMMON_SRC ${COMMON_DIR}/*.cpp)
file(GLOB TEST_SRC ${TEST_DIR}/*.cpp)
set(MAIN_SRC ${SRC_DIR}/main.cpp)

add_executable(main ${MAIN_SRC} ${ALGO_SRC} ${COMMON_SRC} ${TEST_SRC})

# 包含头文件目录
target_include_directories(main PRIVATE ${SRC_DIR} ${ALGO_DIR} ${COMMON_DIR} ${TEST_DIR} ${CMAKE_SOURCE_DIR}/include)

# 测试可执行文件（如有）
if(EXISTS ${CMAKE_SOURCE_DIR}/tests/main_test.cpp)
    add_executable(test_main tests/main_test.cpp ${ALGO_SRC} ${COMMON_SRC})
    target_include_directories(test_main PRIVATE ${SRC_DIR} ${ALGO_DIR} ${COMMON_DIR} ${TEST_DIR} ${CMAKE_SOURCE_DIR}/include)
endif()
