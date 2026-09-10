# ==============================
# Quick Select Test
# ==============================

add_executable(
    test_quick_select
    QuickSelectTest.cpp
)

target_link_libraries(
    test_quick_select
    PRIVATE
    XLWS_DS_algorithm
)

add_test(
    NAME QuickSelectTest
    COMMAND test_quick_select
)