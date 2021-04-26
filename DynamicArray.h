#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <iostream>
#include "DynamicArrayException.h"

using namespace std;

template <class T>
class DynamicArray
{
public:

    // --------------- CTORS

    DynamicArray(T* items, size_t count)
    {
        Resize(count);
        len_ = size_; // in this case lenght equals to size

        for (size_t i=0; i<len_; ++i)
            this->arr_[i] = items[i];
    }

    DynamicArray(size_t size)
    {
        Resize(size);
    }

    DynamicArray(DynamicArray<T> & DynamicArray)
    {
        Resize(DynamicArray.GetSize());
        len_ = DynamicArray.GetLen();

        for (size_t i=0; i<len_; ++i)
            arr_[i] = DynamicArray.Get(i);
    }

    ~DynamicArray()
    {
        delete[] arr_;
    }

    // ----------------------


    T Get(size_t index)
    {
        if (index < 0 || index >= len_)
            throw DynamicArrayException<T>("IndexOutOfRange");
        return arr_[index];
    }

    int GetSize()
    {
        return size_;
    }

    int GetLen()
    {
        return len_;
    }

    void Set(size_t index, T value)
    {
        if (index < 0 || index >= size_)
            throw DynamicArrayException<T>("IndexOutOfRange");
        arr_[index] = value;
    }

    void Resize(size_t newSize)
    // when the object is uninitialized, whole new chunk of memory is allocated
    // otherwise already existing chunk is changed
    {
        if (arr_ == NULL)
            arr_ = (T*)realloc(NULL, sizeof(T)*newSize);
        else
            arr_ = (T*)realloc(arr_, sizeof(T)*newSize);

        if (newSize <= size_)
            len_ = newSize;

        size_ = newSize;
    }

private:

    T* arr_ = NULL;
    size_t size_ = 0;
    size_t len_ = 0;
};

#endif // DYNAMIC_ARRAY_H

