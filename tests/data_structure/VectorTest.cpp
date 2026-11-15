#include <iostream>

#include "XLWS_DS/data_structure/Vector.hpp"
#include "XLWS_DS/algorithm/sort/QuickSort.hpp"

int main(void)
{
    xlws::vector<int> arr;

    arr.push_back(1);
    arr.push_back(34);
    arr.push_back(12);

    for (int x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    xlws::quickSort(arr.begin(), arr.end());
    for (int x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;


    // 缩容
    xlws::vector<int> v;
    v.reserve(100); // 强行申请 100 的容量
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "缩容前: size = " << v.size() << ", capacity = " << v.capacity() << "\n";

    v.shrink_to_fit(); // 触发缩容，容量应该变成 3

    std::cout << "缩容后: size = " << v.size() << ", capacity = " << v.capacity() << "\n";

    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}