#pragma once

#include "XLWS_DS/memory/Memory.hpp"

namespace xlws
{
template <typename T>
class vector
{
public:
    vector() : data_(nullptr), size_(0), capacity_(0)
    {

    }

    ~vector()
    {
        for (std::size_t i = 0; i < size_; ++i)
        {
            xlws::memory::destroy(data_ + i);
        }
        xlws::memory::deallocate(data_);
    }

    std::size_t size() const { return size_; }

    std::size_t capacity() const { return capacity_; }

    void reserve(std::size_t new_capacity) // 保留内存
    {
        if (new_capacity <= capacity_) return;

        T* new_data = xlws::memory::allocate<T>(new_capacity); // 申请内存

        for (std::size_t i = 0; i < size_; ++i)                // 将旧对象移动到新内存
        {
            xlws::memory::construct(new_data + i, std::move(data_[i]));
        }

        for (std::size_t i = 0; i < size_; ++i)                //清除旧对象
        {
            xlws::memory::destroy(data_ + i);
        }
        xlws::memory::deallocate(data_);                       // 清除内存

        data_ = new_data;
        capacity_ = new_capacity;
    }

    void push_back(const T& value)
    {
        if (size_ == capacity_)
        {
            // push_back 只考虑添加数据，不考虑删除数据，所以不用考虑缩容，只用reserve就行
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }

        xlws::memory::construct(data_ + size_, value);
        ++size_;
    }

    T& operator[](std::size_t index)
    {
        return data_[index];
    }

    const T& operator[](std::size_t index) const
    {
        return data_[index];
    }

private:
    T* data_ = nullptr;
    std::size_t capacity_ = 0;
    std::size_t size_ = 0;
    
};

}