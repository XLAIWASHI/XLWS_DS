#pragma once

#include <cstddef>
#include <new>

namespace xlws
{
    namespace memory
    {
        template <typename T>
        T* allocate(std::size_t n) // 分配内存
        {
            if (n == 0)
                return nullptr;
            // operator new 是全局底层函数，不调用构造函数，返回void*；前面加::是明确告诉编译器
            // 要用最顶层的全局 operator new
            return static_cast<T*>(::operator new(n * sizeof(T)));   
        }

        template <typename T, typename... Args>
        void construct(T* p, Args&&... args) // 建造对象
        {
            // ::new (p) T(...) 不要新的内存，就在指针 p 指向的这块内存新建对象
            // 转成 static_cast<void*>(p) 防止类内部重载了特殊的 operator new 导致定位错误
            // forward 的作用是，保持参数原本的属性；左值进去，还是左值；右值进去，还是右值
            ::new (static_cast<void*>(p)) T(std::forward<Args>(args)...);
        }
        
        template <typename T>
        void destroy(T* p) noexcept // 清除对象
        {
            // noexcept 我保证这个函数绝对不会抛出异常
            p->~T(); // 手动调用析构函数
        }

        template <typename T>
        void deallocate(T* p) noexcept // 释放内存
        {
            ::operator delete(p);
        }
    }
}