#include <iostream>

#include "XLWS_DS/algorithm/Sort/ShellSort.hpp"

int main(void)
{
    int arr[] = {5, 2, 8, 1, 3, 6};

    xlws::shellSort(arr, arr + 6);

    for(int value : arr)
    {
        std::cout << value << ' ';
    }

    std::cout << std::endl;

    return 0;
}