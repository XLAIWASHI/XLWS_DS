# tests/algorithm/sort/CMakeLists.txt


# ==============================
# Merge Sort Test
# ==============================

add_executable(
    test_merge_sort
    MergeSortTest.cpp
)

target_link_libraries(
    test_merge_sort
    PRIVATE
    XLWS_DS_algorithm
)

add_test(
    NAME MergeSortTest
    COMMAND test_merge_sort
)


# ==============================
# Select Sort Test
# ==============================

add_executable(
    test_select_sort
    SelectSortTest.cpp
)

target_link_libraries(
    test_select_sort
    PRIVATE
    XLWS_DS_algorithm
)

add_test(
    NAME SelectSortTest
    COMMAND test_select_sort
)


# ==============================
# Shell Sort Test
# ==============================

add_executable(
    test_shell_sort
    ShellSortTest.cpp
)

target_link_libraries(
    test_shell_sort
    PRIVATE
    XLWS_DS_algorithm
)

add_test(
    NAME ShellSortTest
    COMMAND test_shell_sort
)


# ==============================
# Quick Sort Test
# ==============================

add_executable(
    test_quick_sort
    QuickSortTest.cpp
)

target_link_libraries(
    test_quick_sort
    PRIVATE
    XLWS_DS_algorithm
)

add_test(
    NAME QuickSortTest
    COMMAND test_quick_sort
)