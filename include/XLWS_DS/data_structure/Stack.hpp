#pragma once

#include <cstddef>
#include <utility>
#include <stdexcept>

namespace xlws
{
    template <typename T>
    class stack
    {
    public:
        stack() : data_(new T[1]), size_(0), capacity_(1)
        {
        }
        ~stack()
        {
            delete[] data_;
        }

        // 禁止拷贝
        stack(const stack&) = delete;
        stack& operator=(const stack&) = delete;

        bool isEmpty() const { return size_ == 0; }

        void push(T item)
        {
            if (size_ == capacity_)
            {
                resize(capacity_ * 2);
            }
            data_[size_++] = std::move(item);
        }

        T pop()
        {
            if (isEmpty())
            {
                throw std::underflow_error("Pop from empty stack");
            }
            T item = std::move(data_[--size_]);

            if (size_ > 0 && size_ == capacity_ / 4)
            {
                resize(capacity_ / 2);
            }
            return item;
        }
    private:
        void resize(std::size_t newCapacity)
        {
            T* newdata = new T[newCapacity];

            for (std::size_t i = 0; i < size_; i++)
            {
                newdata[i] = std::move(data_[i]);
            }

            delete[] data_;

            data_ = newdata;
            capacity_ = newCapacity;
        }

        T* data_;
        std::size_t capacity_ = 0;
        std::size_t size_ = 0;
    };

}