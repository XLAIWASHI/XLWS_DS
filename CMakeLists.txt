cmake_minimum_required(VERSION 3.10)

project(XLWS_DS
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==============================
# XLWS_DS algorithm 接口库
# ==============================

add_library(XLWS_DS_algorithm INTERFACE)

target_include_directories(XLWS_DS_algorithm
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)

# ==============================
# 测试
# ==============================

enable_testing()

# ==============================
# Merge Sort 测试
# ==============================

add_executable(test_merge_sort
    tests/algorithm/sort/MergeSortTest.cpp
)

target_link_libraries(test_merge_sort
    PRIVATE
        XLWS_DS_algorithm
)

set_target_properties(test_merge_sort
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/tests/algorithm/sort"
)

add_test(
    NAME MergeSortTest
    COMMAND test_merge_sort
)

# ==============================
# Shell Sort 测试
# ==============================

add_executable(test_shell_sort
    tests/algorithm/sort/ShellSortTest.cpp
)

target_link_libraries(test_shell_sort
    PRIVATE
        XLWS_DS_algorithm
)

set_target_properties(test_shell_sort
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY
        "${CMAKE_BINARY_DIR}/tests/algorithm/sort"
)

add_test(
    NAME ShellSortTest
    COMMAND test_shell_sort
)