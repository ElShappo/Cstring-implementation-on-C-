#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "DynamicArrayException.h"

using namespace std;

template <class T>
class DynamicArray
{
public:

    // --------------- CTORS

    DynamicArray() {}

    DynamicArray(T* items, int len)
    {
        if (len < 0 || (len > 0 && items == NULL))
            throw DynamicArrayException<T>("OutOfRange");

        Reserve(len);
        len_ = capacity_; // in this case length equals to size

        for (int i=0; i<len_; ++i)
            this->arr_[i] = items[i];
    }

    DynamicArray(int capacity)
    {
        if (capacity < 0)
            throw DynamicArrayException<T>("OutOfRange");
        Reserve(capacity);
    }

    DynamicArray(DynamicArray<T> & dynamicArray)
    {
        Reserve(dynamicArray.GetCapacity());
        len_ = dynamicArray.GetLen();

        for (int i=0; i<len_; ++i)
            arr_[i] = dynamicArray.Get(i);
    }

    T & operator[](int index)
    {
        if (index >= len_)
            throw DynamicArrayException<T>("IndexOutOfRange");

        return arr_[index];
    }

    bool operator ==(const DynamicArray<T> & array) const
    {
        for (int i=0; i<array.GetLen(); ++i)
        {
            if (array.Get(i) != Get(i))
                return false;
        }
        return true;
    }

    bool operator !=(const DynamicArray<T> & array) const
    {
        for (int i=0; i<array.GetLen(); ++i)
        {
            if (array.Get(i) == Get(i))
                return false;
        }
        return true;
    }

    bool operator =(const DynamicArray<T> & array)
    {
        while (!Empty() )
            PopBack();

        for (int i=0; i<array.GetLen(); ++i)
            PushBack(array[i]);
    }

    ~DynamicArray()
    {
        delete[] arr_;
    }

    // ----------------------


    T Get(int index) const
    {
        if (index >= len_ || index < 0)
        {
            cout << index << " > " << len_ << endl;
            throw DynamicArrayException<T>("IndexOutOfRange");
        }
        return arr_[index];
    }

    int GetCapacity() const noexcept
    {
        return capacity_;
    }

    int GetLen() const noexcept
    {
        return len_;
    }

    void Set(T value, int index)
    {
        if (index > len_-1 || index < 0)
        {
            cout << index << " > " << len_ << endl;
            throw DynamicArrayException<T>("IndexOutOfRange");
        }
        arr_[index] = value;
    }

    void Reserve(int capacity)
    // when the object is uninitialized, whole new chunk of memory is allocated
    // otherwise already existing chunk is changed
    {
        if (capacity < 0)
            throw DynamicArrayException<T>("OutOfRange");

        if (arr_ == NULL)
            arr_ = (T*)realloc(NULL, sizeof(T)*capacity);
        else
            arr_ = (T*)realloc(arr_, sizeof(T)*capacity);

        capacity_ = capacity;

        if (capacity_ < len_)
            len_ = capacity_;
    }

    void Resize(int len)
    // pretty much the same as PopBack
    // this method does not allow to increase the length
    {
        if (len_ < len || len < 0)
            throw DynamicArrayException<T>("IndexOutOfRange");
        else
            len_ = len;

        for (int i=0; i<len_-len; ++i)
            PopBack();
    }

    void Swap(int pos1, int pos2)
    {
        if (pos1 < 0 || pos2 < 0)
            throw DynamicArrayException<T>("OutOfRange");

        swap(arr_[pos1], arr_[pos2]);
    }

    void Insert(T data, int pos)
    {
        if (pos > len_ || pos < 0)
        {
            cout << pos << " > " << len_ << endl;
            throw DynamicArrayException<T>("IndexOutOfRange");
        }

        if (arr_ == NULL)
            arr_ = (T*)realloc(NULL, sizeof(T)*(len_+1));
        else
            arr_ = (T*)realloc(arr_, sizeof(T)*(len_+1));

        ++len_;

        for (int i=len_-2; i>=pos; --i)
            Set(Get(i), i+1);

        arr_[pos] = data;

        if (capacity_ < len_)
            capacity_ = len_;
    }

    void PushBack(T data)
    {
        Insert(data, len_);
    }
    void PushFront(T data)
    {
        Insert(data, 0);
    }
    void Append(DynamicArray<T> buffer)
    {
        for (int i=0; i<buffer.GetLen(); ++i)
            PushBack(buffer.Get(i));
    }

    T PopBack()
    {
        if (arr_ == NULL || len_ == 0 || capacity_ == 0)
            throw DynamicArrayException<T>("Can't pop empty array");
        else
        {
            T buffer = arr_[len_-1];
            arr_ = (T*)realloc(arr_, sizeof(T)*(len_-1));
            --len_;
            return buffer;
        }
    }

    void Shrink_to_fit(int delta = 1)
    {
        if (abs((int)capacity_-(int)len_) > delta)
            capacity_ = len_;
    }

    bool Empty() const noexcept
    {
        if (len_ == 0)
            return true;
        return false;
    }

private:

    T* arr_ = NULL;
    int capacity_ = 0;
    int len_ = 0;
};

#endif // DYNAMIC_ARRAY_H

