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

add_subdirectory(tests)