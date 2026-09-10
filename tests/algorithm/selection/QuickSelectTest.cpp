#include <iostream>

#include "XLWS_DS/algorithm/selection/QuickSelect.hpp"

int main(void)  
{
    int arr[] = {5, 2, 8, 1, 3, 6};

    int* k = xlws::quickSelect(arr, arr + 6, 2);

    std::cout << *k << std::endl;

    return 0;
}