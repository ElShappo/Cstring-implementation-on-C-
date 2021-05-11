#ifndef ARRAY_SEQUENCE_H
#define ARRAY_SEQUENCE_H

#include "DynamicArray.h"
#include "Sequence.h"

template <class T>
class ArraySequence : public Sequence<T>
{
private:
    DynamicArray<T>* array_;

public:

    ArraySequence() { array_ = new DynamicArray<T>(); }
    ArraySequence(T* items, int len) { array_ = new DynamicArray<T>(items, len); }
    ArraySequence(int capacity) { array_ = new DynamicArray<T>(capacity); }
    ArraySequence(DynamicArray<T> & dynamicArray) { array_ = new DynamicArray<T>(dynamicArray); }

    T & operator[](int index) override { return (*array_)[index]; }
    int length() override { return array_->GetLen(); }
    int size() override { return array_->GetLen(); }
    void push_back(T data) override { array_->PushBack(data); }
    void push_front(T data) override { array_->PushFront(data); }
    T pop_back() override { return array_->PopBack(); }
    T get(int index) override { return array_->Get(index); }
    void set(T data, int index) override { array_->Set(data, index); }
    void insert(T data, int index) override { array_->Insert(data, index); }

    // UNIQUE METHODS

    int capacity() { return array_->GetCapacity(); }
    void reserve(int capacity) { array_->Reserve(capacity); }
    void resize(int len) { array_->Resize(len); }
    void swap(int pos1, int pos2) { array_->Swap(pos1, pos2); }
    void shrink_to_fit() { array_->Shrink_to_fit(); }
    bool operator ==(DynamicArray<T> array) { return (array == array_); }
    bool operator !=(DynamicArray<T> array) { return (array != array_); }
};

#endif // ARRAY_SEQUENCE_H
