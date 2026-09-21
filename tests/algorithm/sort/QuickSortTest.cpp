#include <iostream>

#include "XLWS_DS/algorithm/sort/QuickSort.hpp"

int main(void)  
{
    int arr[] = {5, 2, 8, 1, 3, 6, 1, 1, 1, 1, 1, 1};

    xlws::quickSort(arr, arr + 12);

    for(int value : arr)
    {
        std::cout << value << ' ';
    }

    std::cout << std::endl;

    return 0;
}