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
    RandomIt quickSelect(RandomIt first, RandomIt last,
        typename std::iterator_traits<RandomIt>::difference_type k, Compare cmp)
    {
        using DifferenceType = typename std::iterator_traits<RandomIt>::difference_type;
        DifferenceType lo = 0, hi = (last - first) - 1;

        while (lo < hi)
        {
            RandomIt split = detail::partition(first + lo, first + hi + 1, cmp);
            DifferenceType j = split - first;
            
            if (j < k)
            {
                lo = j + 1;
            }
            else if (j > k)
            {
                hi = j - 1;
            }
            else
            {
                return first + j;
            }
        }
        return first + lo;
    }

    template <typename RandomIt>
    RandomIt quickSelect(RandomIt first, RandomIt last,
        typename std::iterator_traits<RandomIt>::difference_type k)
    {
        return quickSelect(first, last, k, std::less<>{});
    }
}