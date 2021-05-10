#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "LinkedListException.h"

template <class T>
class LinkedList
{
public:

    LinkedList(){}

    LinkedList(T* items, int count)
    {
        if (count < 0)
            throw LinkedListException<T>("IndexOutOfRange");

        for (int i=0; i<count; ++i)
        {
            // cout << "Iteration (" << i << "); size = " << GetLen() << endl;
            PushBack(items[i]);
        }
    }

    LinkedList(LinkedList<T> & list)
    {
        // cout << "Copy ctor has been called." << endl;
        /*
        cout << "List size: " << list.GetLen() << endl;

        for (int i=0; i<list.GetLen(); ++i)
            cout << list.Get(i) << endl;
        */

        for (int i=0; i<list.GetLen(); ++i)
            PushBack(list.Get(i));
    }

    void Insert(T data, int index)
    {
        if (index < 0 || index > len_)
            throw LinkedListException<T>("IndexOutOfRange");

        ++len_;

        int count = 0;
        Node* buffer = head_;

        if (index == 0)
        {
            head_ = new Node(data, buffer);
        }
        else
        {
            while (count < index-1)
            {
                buffer = buffer->next_;
                ++count;
            }
            // now buffer holds either head_ or next_ of Node with number n-2 (either head_ or Node with number n-1)
            //cout << buffer->data_ << endl;

            Node* oldNext = buffer->next_;
            buffer->next_ = new Node(data, oldNext);
        }
    }

    void PushBack(T data) { Insert(data, len_); }
    void PushFront(T data) { Insert(data, 0); }

    T PopBack()
    {
        if (len_ == 0 || head_ == NULL)
            throw LinkedListException<T>("Can't pop empty list");

        int count = 0;
        Node* buffer = head_;

        while (count < len_-1)
        {
            buffer = buffer->next_;
            ++count;
        }

        //if (buffer == NULL)
            //throw LinkedListException<T>("Can't pop empty list");

        //cout << buffer->data_ << endl;

        T buff = buffer->data_;
        free(buffer->next_);
        buffer->next_ = NULL;
        --len_;

        return buff;
    }

    T Get(int index)
    {
        if (index < 0 || index >= len_)
            throw LinkedListException<T>("IndexOutOfRange");

        Node* buffer = head_;

        for (int i=0; i<index; ++i)
            buffer = buffer->next_;

        return buffer->data_;
    }

    void Set(T data, int index)
    {
        if (index < 0 || index >= len_)
            throw LinkedListException<T>("IndexOutOfRange");

        Node* buffer = head_;

        for (int i=0; i<index; ++i)
            buffer = buffer->next_;

        buffer->data_ = data;
    }

    class LinkedList<T>* GetSubList(int iStart, int iEnd)
    {
        int size = iEnd-iStart+1;

        T items[size];

        for (int i=0; i<size; ++i)
            items[i] = Get(iStart+i);

        return new LinkedList(items, size);
    }

    class LinkedList<T>* Append(LinkedList<T> list)
    {
        class LinkedList<T>* newList = new LinkedList(*this);

        for (int i=0; i<list.GetLen(); ++i)
        {
            //cout << list.Get(i) << endl;
            newList->PushBack(list.Get(i));
        }

        return newList;
    }

    T GetFirst()
    {
        return Get(0);
    }

    T GetLast()
    {
        return Get(len_-1);
    }

    size_t GetLen()
    {
        return len_;
    }

private:
    class Node
    {
    public:
        Node(T data = T(), Node* next = nullptr)
        {
            data_ = data;
            next_ = next;
        }
        ~Node()
        {
            delete next;
        }

        Node* next_ = nullptr;
        T data_;
    };

    Node* head_ = nullptr;
    size_t len_ = 0;

};

/*
LinkedList(T* items, int count)
    {


    }

    LinkedList()
    {


    }

    LinkedList(LinkedList<T> & list const)
    {

    }

    T GetFirst()
    {

    }

    T GetLast()
    {

    }

    T Get(int index)
    {

    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex)
    {

    }

    int GetLength()
    {

    }

    void Append(T item)
    {

    }

    void Prepend(T item)
    {

    }

    void InsertAt(T item, int index)
    {

    }

    LinkedList<T*> Concat(LinkedList<T> *list)
    {

    }
*/

#endif // LINKED_LIST_H
