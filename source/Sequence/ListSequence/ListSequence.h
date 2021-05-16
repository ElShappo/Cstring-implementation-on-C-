#ifndef LIST_SEQUENCE_H
#define LIST_SEQUENCE_H

#include "../../LinkedList/LinkedList.h"
#include "../Sequence.h"

template<class T, template<typename> typename C = LinkedList>
class ListSequence : public Sequence<T, C>
{
private:
    LinkedList<T>* list_;

public:
    ListSequence() { list_ = new LinkedList<T>(); }
    ListSequence(T* items, int count) { list_ = new LinkedList<T>(items, count); }
    ListSequence(ListSequence<T> & list) { list_ = new LinkedList<T>(list); }

    T & operator[](int index) override { return (*list_)[index]; }
    bool operator ==(const LinkedList<T> & list) const { return (list == *list_); }
    bool operator !=(const LinkedList<T> & list) const { return (list != *list_); }
    void operator =(LinkedList<T> & list) { *list_ = list; }

    int length() override { return list_->GetLen(); }
    int size() override { return list_->GetLen(); }
    void push_back(T data) override { list_->PushBack(data); }
    void push_front(T data) override { list_->PushFront(data); }
    T pop_back() override { return list_->PopBack(); }
    T get(int index) override { return list_->Get(index); }
    void set(T data, int index) override { list_->Set(data, index); }
    void insert(T data, int index) override { list_->Insert(data, index); }
    bool empty() override { return list_->Empty(); }

    T first() { list_->GetFirst(); }
    T last() {list_->GetLast(); }
    void append(LinkedList<T> list) {list_->Append(list); }
    class LinkedList<T>* sublist(int iStart, int iEnd) {list_->GetSubList(iStart, iEnd); }
};

#endif // LIST_SEQUENCE_H
