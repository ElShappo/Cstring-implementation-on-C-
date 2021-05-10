#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "DynamicArray.h"
#include "Sequence.h"

template <class T>
class ArraySequence : public Sequence
{
private:
    DynamicArray array_;

public:

    ArraySequence(T* items, size_t count)
    {
        array_.Resize(count);
        array_.capacity_ = array_.capacity_; // in this case length equals to size

        for (size_t i=0; i<array_.capacity_; ++i)
            this->array_.arr_[i] = array_.items[i];
    }

    ArraySequence(size_t size)
    {
        array_.Resize(size);
    }

    ArraySequence(ArraySequence<T> & ArraySequence)
    {
        array_.Resize(array_.GetSize());
        array_.capacity_ = array_.GetLen();

        for (size_t i=0; i<array_.capacity_; ++i)
            arr_[i] = array_.Get(i);
    }

    T & operator[](size_t pos)
    {
        return array_.Get(pos);
    }

    T capacity()
    {
        return array_.GetCapacity();
    }

    T size()
    {
        return array_.GetSize();
    }

    void push_back(T data)
    {
        array_.
    }

    T pop_back()
    {

    }

};

#endif // ARRAY_SEQUENCE_H
