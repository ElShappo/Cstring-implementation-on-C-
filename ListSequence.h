#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "LinkedList.h"
#include "Sequence.h"

template<class T>
class ListSequence : public Sequence<T>
{
private:
    LinkedList<T>* list_;

public:
    ListSequence() { list_ = new LinkedList<T>(); }
    ListSequence(T* items, int count) { list_ = new LinkedList<T>(items, count); }
    ListSequence(ListSequence<T> & list) { list_ = new LinkedList<T>(list); }

    T & operator[](int index) override { return (*list_)[index]; }
    int length() override { return list_->GetLen(); }
    void push_back(T data) override { list_->PushBack(data); }
    void push_front(T data) override { list_->PushFront(data); }
    T pop_back() override { return list_->PopBack(); }
    void get(int index) override { list_->Get(index); }
    void set(T data, int index) override { list_->Set(data, index); }
    void insert(T data, int index) override { list_->Insert(data, index); }

    T first() { list_.GetFirst(); }
    T last() {list_.GetLast(); }
    class LinkedList<T>* append(LinkedList<T> list) {list_.Append(list); }
    class LinkedList<T>* sublist(int iStart, int iEnd) {list_.GetSubList(iStart, iEnd); }
};

#endif // LIST_SEQUENCE_H
