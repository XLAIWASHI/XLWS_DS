#pragma once

#include <iterator>
#include <functional>
#include <utility>
#include "XLWS_DS/utility/Swap.hpp"

namespace xlws
{
    namespace detail
    {
        template <typename RandomIt, typename Compare>
        std::pair<RandomIt, RandomIt> partition(RandomIt first, RandomIt last, Compare cmp)
        {
            using ValueType = typename std::iterator_traits<RandomIt>::value_type;
            using DifferenceType = typename std::iterator_traits<RandomIt>::difference_type;

            const DifferenceType size = last - first;

            DifferenceType lo = 0;
            DifferenceType hi = size - 1;
            DifferenceType i = lo;

            const ValueType pivot = *first;

            while (i <= hi)
            {
                if (cmp(*(first + i), pivot))
                {
                    xlws::swap(first + i, first + lo);
                    ++lo;
                    ++i;
                }
                else if (cmp(pivot, *(first + i)))
                {
                    xlws::swap(first + i, first + hi);
                    hi--;
                }
                else
                {
                    ++i;
                }
            }
            
            return {first + lo, first + hi + 1};
        }
    }

    template <typename RandomIt, typename Compare>
    void quickSort(RandomIt first, RandomIt last, Compare cmp)
    {
        if (last - first <= 1)
        {
            return;
        }
        const auto result = detail::partition(first, last, cmp);

        const RandomIt middleFirst = result.first;
        const RandomIt middleLast = result.second;

        quickSort(first, middleFirst, cmp);
        quickSort(middleLast, last, cmp);
    }

    template <typename RandomIt>
    void quickSort(RandomIt first, RandomIt last)
    {
        quickSort(first, last, std::less<>{});
    }
}