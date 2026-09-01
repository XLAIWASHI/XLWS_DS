#pragma once

namespace xlws
{
    template <typename It>
    void swap(It a, It b)
    {
        auto temp = *a;
        *a = *b;
        *b = temp;
    }
}