#ifndef LINKED_LIST
#define LINKED_LIST

#include "LinkedListException.h"

template <class T>
class LinkedList
{
public:

    LinkedList(){}

    LinkedList(T* items, int count)
    {
        for (int i=0; i<count; ++i)
        {
            cout << "Iteration (" << i << "); size = " << GetSize() << endl;
            PushBack(items[i]);
        }
    }

    LinkedList(LinkedList<T> & list)
    {
        /*
        cout << "List size: " << list.GetSize() << endl;

        for (int i=0; i<list.GetSize(); ++i)
            cout << list.Get(i) << endl;
        */

        for (int i=0; i<list.GetSize(); ++i)
            PushBack(list.Get(i));
    }

    void Insert(T data, int index)
    {
        if (index < 0 || index > size_)
            throw LinkedListException("IndexOutOfRange");

        ++size_;

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
            cout << buffer->data_ << endl;

            Node* oldNext = buffer->next_;
            buffer->next_ = new Node(data, oldNext);
        }
    }

    void PushBack(T data) { Insert(data, size_); }
    void PushFront(T data) { Insert(data, 0); }

    T Get(int index)
    {
        if (index < 0 || index >= size_)
            throw LinkedListException("IndexOutOfRange");

        Node* buffer = head_;

        for (int i=0; i<index; ++i)
            buffer = buffer->next_;

        return buffer->data_;
    }

    /*
    class LinkedList<T>* GetSubList(int iStart, int iEnd)
    {
        if (iStart < 0 || iEnd < 0 || iStart > size_ || iEnd > size_ || iEnd < iStart)
            throw LinkedListException("IndexOutOfRange");

        Node* buffer = head_;
        T data[iEnd-iStart];

        int count = 0;

        while (count < iStart)
        {
            buffer = buffer->next_;
            ++count;
        }
        for (int i=0; i<(iEnd-iStart+1); ++i)
        {
            data[i] = buffer->data_;
            buffer = buffer->next_;
        }
        return new LinkedList(data, iEnd-iStart+1);
    }
    */

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
        class LinkedList<T> newList(this);

        for (int i=0; i<list.GetSize(); ++i)
            newList.PushBack(list.Get(i));
    }

    T GetFirst()
    {
        return Get(0);
    }

    T GetLast()
    {
        return Get(size_-1);
    }

    size_t GetSize()
    {
        return size_;
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
    size_t size_ = 0;

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

#endif // LINKED_LIST
