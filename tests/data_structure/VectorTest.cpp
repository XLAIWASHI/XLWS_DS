#include <iostream>

#include "XLWS_DS/data_structure/Vector.hpp"

int main(void)
{
    xlws::vector<int> arr;

    arr.push_back(1);
    arr.push_back(34);
    arr.push_back(12);

    // for (int i = 0; i < arr.size(); ++i)
    // {
    //     std::cout << arr[i] << " ";
    // }

    std::cout << arr.size() << " " << arr.capacity();

    return 0;
}