#pragma once

#include <utility>
#include <functional>

#include "XLWS_DS/data_structure/Vector.hpp"
#include "XLWS_DS/utility/Swap.hpp"

namespace xlws
{
template <typename T, typename Compare = std::less<T>>
class heap
{
public:
    heap() = default;

    void push(const T& value)
    {
        data_.push_back(value);
        swim(data_.size() - 1);
    }

    void pop()
    {
        if (empty()) return;
        xlws::swap(data_[0], data_[data_.size() - 1]);
        data_.pop_back();
        if (!empty())
            sink(0);
    }

    T& top() { return data_[0]; }
    const T& top() const { return data_[0]; }
    bool empty() { return data_.empty(); }
    std::size_t size() const { return data_.size(); }



private:
    xlws::vector<T> data_;
    Compare cmp_;

    void swim(std::size_t index)
    {
        while (index > 0 && cmp_(data_[(index - 1) >> 1], data_[index]))
        {
            xlws::swap(data_[(index - 1) >> 1], data_[index]);
            index = (index - 1) >> 1;
        }
    }

    void sink(std::size_t index)
    {
        std::size_t n = data_.size();
        while (2 * index + 1 < n)
        {
            std::size_t j = 2 * index + 1;
            if (j + 1 < n && cmp_(data_[j], data_[j + 1]))
                ++j;
            if (!cmp_(data_[j], data_[index]))
                break;
            xlws::swap(data_[j], data_[index]);
            index = j;
        }
    }
};
}