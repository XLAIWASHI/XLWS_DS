#pragma once

#include <iterator>
#include <functional>
#include "XLWS_DS/utility/Swap.hpp"

namespace xlws
{
    namespace detail
    {
        template <typename RandomIt, typename Compare>
        RandomIt partition(RandomIt first, RandomIt last, Compare cmp)
        {
            using ValueType = typename std::iterator_traits<RandomIt>::value_type;
            using DifferenceType = typename std::iterator_traits<RandomIt>::difference_type;

            const DifferenceType size = last - first;

            DifferenceType lo = 0;
            DifferenceType hi = size - 1;
            
            const ValueType pivot = *first;

            while (true)
            {
                // 保证pivot不变位置
                while (lo < hi && cmp(*(first + lo + 1), pivot))
                {
                    ++lo;
                }

                while (lo < hi && cmp(pivot, *(first + hi)))
                {
                    --hi;
                }

                if (lo >= hi)
                {
                    break;
                }

                xlws::swap(first + lo + 1, first + hi);
                ++lo;
                --hi;
            }
            xlws::swap(first, first + hi);
            return first + hi;
        }
    }

    template <typename RandomIt, typename Compare>
    void quickSort(RandomIt first, RandomIt last, Compare cmp)
    {
        if (last - first <= 1)
        {
            return;
        }
        RandomIt split = detail::partition(first, last, cmp);
        quickSort(first, split, cmp);
        quickSort(split + 1, last, cmp);
    }

    template <typename RandomIt>
    void quickSort(RandomIt first, RandomIt last)
    {
        quickSort(first, last, std::less<>{});
    }
}