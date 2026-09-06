#pragma once

#include <iterator>
#include <utility>
#include <cstddef>
#include <functional>

namespace xlws
{
    namespace detail
    {
        template <typename RandomIt, typename Compare>
        void merge(RandomIt first, RandomIt mid, RandomIt last, Compare cmp)
        {
            using ValueType = typename std::iterator_traits<RandomIt>::value_type;
            // using 等价于 typedef 目的是在当前作用域内创建一个新名字
            // typename 显式类型指示器，把后面的名字当作一个类型来处理
            // std::iterator_traits<RandomIt> 标准模板类（类型萃取器），接受迭代器类型 RandomIt ,
            // "询问" 该迭代器的各种属性
            // value_type 是 iterator_traits 内部定义的一个嵌套类型，表示该迭代器指向的元素的类型
            const auto leftSize = mid - first;
            const auto rightSize = last - mid;

            ValueType* temp = new ValueType[leftSize + rightSize];

            RandomIt left = first; // 创建一个迭代器 left，让它从原地址的第一个元素开始遍历
            RandomIt right = mid;

            std::size_t index = 0;

            while (left != mid && right != last)
            {
                if (cmp(*right, *left))
                {
                    temp[index++] = *right++;
                }
                else
                {
                    temp[index++] = *left++;
                }
            }
            // 单侧提前走完
            while (left != mid)
            {
                temp[index++] = *left++;
            }
            while (right != last)
            {
                temp[index++] = *right++;
            }
            // 移动回原地址
            for (std::size_t i = 0; i < index; ++i)
            {
                *(first + i) = std::move(temp[i]);
            }

            delete[] temp;
        }
    }

    template <typename RandomIt, typename Compare>
    void mergeSort(RandomIt first, RandomIt last, Compare cmp)
    {
        const auto distance = last - first;

        if (distance <= 1)
            return;
        
        RandomIt mid = first + distance / 2;

        // 将区间 [first, last) 分成 [first, mid) 和 [mid, last)
        mergeSort(first, mid, cmp);
        mergeSort(mid, last, cmp);

        detail::merge(first, mid, last, cmp);
    }

    template <typename RandomIt>
    void mergeSort(RandomIt first, RandomIt last)
    {
        mergeSort(first, last, std::less<>{});
        //less 小于比较器
    }
}