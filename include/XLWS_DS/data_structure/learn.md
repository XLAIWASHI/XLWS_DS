# 小结：为什么 vector 要避开 new[] / delete[]

## 背景

写 stack 扩容时用到了：

```cpp
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
```

## 原因

1. `new T[n]` 要求 T 可默认构造：调用 n 次默认构造函数 `T()` ，若 T 没有无参构造，则编译失败
vector 要支持任意类型，必须能装 **没有无参构造** 的 T 
2. `new[]` + `delete[]` 造成白构 + 白析构
capacity = 16， size = 3 时， `new T[16]` 真的构造了 16 个对象
其中 `[size, capacity)` 从来没有装过数据
