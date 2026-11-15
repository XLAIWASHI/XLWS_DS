#pragma once

namespace xlws
{
    template <typename T>
    void swap(T& a, T& b)
    {
        T temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }

    template <typename ForwardIt1, typename ForwardIt2>
    void iter_swap(ForwardIt1 a, ForwardIt2 b)
    {
        swap(*a, *b);
    }
}