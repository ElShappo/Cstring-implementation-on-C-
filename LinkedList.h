#ifndef LINKED_LIST
#define LINKED_LIST

#include "LinkedListException.h"

template <class T>
class LinkedList
{
public:

    LinkedList()
    {

    }

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

    void PushBack(T data)
    {
        ++size_;

        if (head_ == nullptr)
            head_ = new Node(data);
        else
        {
            Node* buffer = head_;

            while (buffer->next_ != nullptr)
                buffer = buffer->next_;

            buffer->next_ = new Node(data);
        }
    }

    T Get(int index)
    {
        if (index < 0 || index >= size_)
            throw LinkedListException("IndexOutOfRange");

        Node* buffer = head_;

        for (int i=0; i<index; ++i)
            buffer = buffer->next_;

        return buffer->data_;
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
