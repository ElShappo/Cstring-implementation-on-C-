#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "DynamicArray.h"

template <class T>
class ArraySequence
{
private:
    DynamicArray array_;

public:

    ArraySequence(T* items, size_t count)
    {
        array_.Resize(count);
        array_.len_ = array_.size_; // in this case length equals to size

        for (size_t i=0; i<array_.len_; ++i)
            this->array_.arr_[i] = array_.items[i];
    }

    ArraySequence(size_t size)
    {
        array_.Resize(size);
    }

    ArraySequence(ArraySequence<T> & ArraySequence)
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

    T at(size_t pos)
    {
        return array_.Get()
    }

};

#endif // ARRAY_SEQUENCE_H
