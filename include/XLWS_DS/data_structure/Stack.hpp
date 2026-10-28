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
        stack() : data(new T[1]), size(0), capacity(1)
        {
        }
        ~stack()
        {
            delete[] data;
        }

        // 禁止拷贝
        stack(const stack&) = delete;
        stack& operator=(const stack&) = delete;

        bool isEmpty() const { return size == 0; }

        void push(T item)
        {
            if (size == capacity)
            {
                resize(capacity * 2);
            }
            data[size++] = std::move(item);
        }

        T pop()
        {
            if (isEmpty())
            {
                throw std::underflow_error("Pop from empty stack");
            }
            T item = std::move(data[--size]);

            if (size > 0 && size == capacity / 4)
            {
                resize(capacity / 2);
            }
            return item;
        }
    private:
        void resize(std::size_t newCapacity)
        {
            T* newData = new T[newCapacity];

            for (std::size_t i = 0; i < size; i++)
            {
                newData[i] = std::move(data[i]);
            }

            delete[] data;

            data = newData;
            capacity = newCapacity;
        }

        T* data;
        std::size_t capacity = 0;
        std::size_t size = 0;
    };

}