#include <iostream>
#include <cstddef>

#include "XLWS_DS/data_structure/Stack.hpp"

int main(void)
{
    xlws::Stack<int> st = xlws::Stack<int>();
    for (size_t i = 0; i < 10; i++)
    {
        st.push(i);
    }

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << st.pop() << " ";
    }
    std::cout << std::endl;
}