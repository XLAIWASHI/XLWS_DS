#pragma once

#include <iterator>
#include <functional>

namespace xlws
{
    template <typename RandomIt, typename Compare>
    void shellSort(RandomIt first, RandomIt last, Compare cmp)
    {
        using DifferenceType = typename std::iterator_traits<RandomIt>::difference_type;

        const auto size = last - first;
        DifferenceType h = 1;
        while(3 * h + 1 < size)
        {
            h = 3 * h + 1;
        }

        while(h >= 1)
        {
            for(DifferenceType i = h; i < size; i++)
            {
                for(DifferenceType j = i; j >= h && cmp(*(first + i), *(first + j - h)); j-= h)
                {
                    //todo
                }
            }
            h = (h - 1) / 3;
        }
    }

    template <typename RandomIt>
    void shellSort(RandomIt first, RandomIt last)
    {
        shellSort(first, last, std::less<>{});
    }
}