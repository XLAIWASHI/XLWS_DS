#pragma once

#include <iterator>
#include <functional>
#include "XLWS_DS/utility/swap.hpp"

namespace xlws
{
    template <typename RandomIt, typename Compare>
    void selectSort(RandomIt first, RandomIt last, Compare cmp)
    {
        using DifferenceType = typename std::iterator_traits<RandomIt>::difference_type;

        const DifferenceType size = last - first;

        for (DifferenceType i = 0; i < size; i++)
        {
            DifferenceType min = i;
            for (DifferenceType j = i + 1; j < size; j++)
            {
                if (cmp(*(first + j), *(first + min)))
                {
                    min = j;
                }
            }
            xlws::swap(first + i, first + min);
        }
    }

    template <typename RandomIt>
    void selectSort(RandomIt first, RandomIt last)
    {
        selectSort(first, last, std::less<>{});
    }
}