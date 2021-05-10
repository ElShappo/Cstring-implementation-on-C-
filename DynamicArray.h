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
        Reserve(count);
        len_ = capacity_; // in this case length equals to size

        for (size_t i=0; i<len_; ++i)
            this->arr_[i] = items[i];
    }

    DynamicArray(size_t size)
    {
        Reserve(size);
    }

    DynamicArray(DynamicArray<T> & DynamicArray)
    {
        Reserve(DynamicArray.GetSize());
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
        if (index >= len_)
            throw DynamicArrayException<T>("IndexOutOfRange");
        return arr_[index];
    }

    int GetSize()
    {
        return capacity_;
    }

    int GetLen()
    {
        return len_;
    }

    void Set(size_t index, T value)
    {
        if (index >= capacity_)
            throw DynamicArrayException<T>("IndexOutOfRange");
        arr_[index] = value;
    }

    void Reserve(size_t capacity)
    // when the object is uninitialized, whole new chunk of memory is allocated
    // otherwise already existing chunk is changed
    {
        if (arr_ == NULL)
            arr_ = (T*)realloc(NULL, sizeof(T)*capacity);
        else
            arr_ = (T*)realloc(arr_, sizeof(T)*capacity);

        capacity_ = capacity;

        if (capacity_ < len_)
            len_ = capacity_;

        //if (newSize <= capacity_)
            //len_ = newSize;

        //capacity_ = newSize;
    }

    void Swap(size_t pos1, size_t pos2)
    {
        swap(arr_[pos1], arr_[pos2]);

    }

    void Insert(T data, size_t pos)
    {
        if (pos > len_)
            throw DynamicArrayException<T>("IndexOutOfRange");

            /*
        T newArr[len_+1];

        for (int i=0; i<pos; ++i)
            newArr[i] = arr_[i];

        newArr[pos] = data;

        for (int i=pos+1; i<len_+1; ++i)
            newArr[i] = arr_[i-1];

        free(arr_);
        arr_ = newArr;

        ++len_;

        if (capacity_ < len_)
            capacity_ = len_;

        */

        if (arr_ == NULL)
            arr_ = (T*)realloc(NULL, sizeof(T)*(len_+1));
        else
            arr_ = (T*)realloc(arr_, sizeof(T)*(len_+1));

        for (int i=pos+1; i<len_+1; ++i)
        {
            T buffer = Get(i);
            Set(i, Get(i-1));
            Set(i+1, buffer);
        }

        arr_[pos] = data;

        ++len_;

        if (capacity_ < len_)
            capacity_ = len_;


        /*
        DynamicArray* temp = new DynamicArray(len_+1);

        for (int i=0; i<pos; ++i)
            temp->Set(i, Get(i));

        temp->Set(pos, data);

        for (int i=pos+1; i<len_+1; ++i)
            temp->Set(i, Get(i-1));

        free(arr_);
        arr_ = temp->arr_;

        ++len_;

        if (capacity_ < len_)
            capacity_ = len_;

        */
    }

    void PushBack(T data)
    {
        Insert(data, len_);
    }

    T PopBack()
    {
        if (arr_ == NULL || len_ == 0 || capacity_ == 0)
            throw DynamicArrayException<T>("Can't pop empty array");
        else
        {
            T buffer = arr_[len_-1];
            arr_ = (T*)realloc(arr_, sizeof(T)*(len_-1));
            return buffer;
        }
    }

    //void Shrink_to_fit

private:

    T* arr_ = NULL;
    size_t capacity_ = 0;
    size_t len_ = 0;
};

#endif // DYNAMIC_ARRAY_H

