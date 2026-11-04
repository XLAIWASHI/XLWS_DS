#include <iostream>

#include "XLWS_DS/data_structure/Vector.hpp"

int main(void)
{
    xlws::vector<int> arr;

    arr.push_back(1);
    arr.push_back(34);
    arr.push_back(12);

    for (int i = 0; i < arr.size(); ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << arr.size() << " " << arr.capacity() << std::endl;

    std::cout << "front: " << arr.front() << " " << "back: " << arr.back() << std::endl;

    std::cout << arr.empty() << std::endl;

    arr.pop_back();

    std::cout << "pop_back back: " << arr.back() << std::endl;

    

    return 0;
}