#pragma once

#include <iterator>
#include <functional>

namespace xlws
{
    template <typename RandomIt, typename Compare>
    void shellSort(RandomIt first, RandomIt last, Compare cmp)
    {
        using DifferenceType = typename std::iterator_traits<RandomIt>::difference_type;
        using ValueType = typename std::iterator_traits<RandomIt>::value_type;

        const DifferenceType size = last - first;
        DifferenceType h = 1;
        while(3 * h + 1 < size)
        {
            h = 3 * h + 1;
        }

        while(h >= 1)
        {
            for(DifferenceType i = h; i < size; i++)
            {
                ValueType key = *(first + i); // 当前元素

                DifferenceType j = i;
                for(; j >= h && cmp(key, *(first + j - h)); j-= h)
                {
                    *(first + j) = *(first + j - h);
                }
                *(first + j) = key;
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