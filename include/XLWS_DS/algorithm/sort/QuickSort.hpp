#pragma once

#include <iterator>
#include <functional>
#include <utility>
#include <random>
#include "XLWS_DS/utility/Swap.hpp"

namespace xlws
{
    namespace detail
    {
        template <typename RandomIt>
        void choosePivotRandomly(RandomIt first, RandomIt last)
        {
            using DifferenceType = typename std::iterator_traits<RandomIt>::difference_type;
            
            static std::mt19937 gen(std::random_device{}());

            std::uniform_int_distribution<DifferenceType> dist(0, last - first - 1);

            RandomIt pivot = first + dist(gen);

            xlws::iter_swap(first, pivot);
        }

        template <typename RandomIt, typename Compare>
        std::pair<RandomIt, RandomIt> partition(RandomIt first, RandomIt last, Compare cmp)
        {
            using ValueType = typename std::iterator_traits<RandomIt>::value_type;
            using DifferenceType = typename std::iterator_traits<RandomIt>::difference_type;

            const DifferenceType size = last - first;

            DifferenceType lo = 0;
            DifferenceType hi = size - 1;
            DifferenceType i = lo;

            // 随机选取pivot
            detail::choosePivotRandomly(first, last);
            const ValueType pivot = *first;

            while (i <= hi)
            {
                if (cmp(*(first + i), pivot))
                {
                    xlws::iter_swap(first + i, first + lo);
                    ++lo;
                    ++i;
                }
                else if (cmp(pivot, *(first + i)))
                {
                    xlws::iter_swap(first + i, first + hi);
                    --hi;
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
        while (last - first > 1)
        {
            const auto result = detail::partition(first, last, cmp);

            const RandomIt middleFirst = result.first;
            const RandomIt middleLast = result.second;

            const auto leftSize = middleFirst - first;
            const auto rightSize = last - middleLast;

            if (leftSize < rightSize)
            {
                // 左边小：递归处理左边
                quickSort(first, middleFirst, cmp);
                first = middleLast;
            }
            else
            {
                // 右边小：递归处理右边
                quickSort(middleLast, last, cmp);
                last = middleFirst;
            }
        }
    }

    template <typename RandomIt>
    void quickSort(RandomIt first, RandomIt last)
    {
        quickSort(first, last, std::less<>{});
    }
}