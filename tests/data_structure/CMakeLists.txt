# ==============================
# Stack Test
# ==============================

add_executable(
    test_stack
    StackTest.cpp
)

target_link_libraries(
    test_stack
    PRIVATE
    XLWS_DS_algorithm
)

add_test(
    NAME StackTest
    COMMAND test_stack
)