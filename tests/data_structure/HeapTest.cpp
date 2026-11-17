#include <iostream>
#include <cstddef>

#include "XLWS_DS/data_structure/Heap.hpp"

int main(void)
{
    xlws::heap<int> h;

    h.push(30);
    h.push(10);
    h.push(50);
    h.push(20);

    std::cout << "size: " << h.size() << '\n';
    std::cout << "top: " << h.top() << '\n';

    h.pop();
    std::cout << "size: " << h.size() << '\n';
    std::cout << "top: " << h.top() << '\n';

    h.pop();
    std::cout << "size: " << h.size() << '\n';
    std::cout << "top: " << h.top() << '\n';

return 0;
}