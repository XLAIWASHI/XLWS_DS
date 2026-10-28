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
    XLWS_DS_data_structure
)

add_test(
    NAME StackTest
    COMMAND test_stack
)