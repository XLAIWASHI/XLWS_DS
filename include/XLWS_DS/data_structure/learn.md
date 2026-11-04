# 小结1：为什么 vector 要避开 new[] / delete[]

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
其中 `[size, capacity)` 从来没有装过数据；
`delete`时又要将这13个没有数据的对象删掉，这个就是 **白构造** 和 **白析构** 这13个对象完全是不必要的

## 关于“用移动构造”

扩容/缩容时要把旧数据搬到新内存，旧对象反正要销毁，所以直接 **移动** 而不是 **拷贝** 

- 拷贝：新对象再申请一次资源 + 复制内容 -> 旧对象销毁时释放自己的资源

- 移动：新对象 **直接接管旧对象的资源** -> 旧对象被掏空，销毁时几乎零成本

省掉的时一次资源申请 + 内容复制的开销

## 空间，对象，资源

以前我只知道有开辟空间这个东西，但是现在我知道了，并不只有这一个操作，new的时候

- 空间：allocate 要来的原始内从，没有类型，没有对象；此时指定的类型只是作为要空间的参考，需要获取多少空间

- 对象：construct 之后，这段内存正式变为，有类型，有生命周期的东西；值是在这里给的

- 资源：对象额外申请的、存值的外部内存，需要手动归还

# 小结2：const T& operator[]

## const的是什么？

- const 就是一种“权限控制”
- 对象没有变，只是被加上了“只读”的权限
- 带有const的对象，只能调用带有const后缀的成员函数

## 为什么operator[]必须写两个版本？

1. T& operator[](size_t index)

- **权限** 读写
- 可以读取，也可以赋值修改

2. const T& operator[](size_t index) const

- **权限** 只读
- 给 const vector 对象使用
- 只能看，不能改

## 什么场景下需要使用“只读对象”

函数传参。为了不产生深拷贝，用& ，为了防止修改原数据，加const

```cpp
void printVector(const vector<T>& v)
```

# 小结3：浅拷贝和深拷贝

- **浅拷贝**： 只复制 **指针** 两个对象共享一块内存
- **深拷贝**： 重新申请一块新内存，把内容复制过去，两个对象拥有各自独立的内存