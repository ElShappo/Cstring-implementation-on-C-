#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"

using namespace std;


template <class T>
class Cstring
{
    T GetSubstr(int index1, int index2);
    T MatchSubstr(Cstring<T> str);
};

class ListTest
{
    virtual void EmptyListTest() = 0;
    virtual void CopyListTest() = 0;
    virtual void ItemsListTest() = 0;
};

template <typename T>
void EmptyListTest(T* items, int size)
{
    LinkedList<T> obj;

    for (int i=0; i<size; ++i)
        obj.PushBack(items[i]);

    PrintData(obj);
}

template <typename T>
void ItemsListTest(T* items, int size)
{
    LinkedList<T> obj(items, size);
    PrintData(obj);
}

template <typename T>
void PrintData(LinkedList<T> obj)
{
    for (int i=0; i<obj.GetSize(); ++i)
        cout << obj.Get(i) << endl;
}


int main()
{
    try
    {
        /*
        double arr[4] = {1,3,3,4};

        DynamicArray<double> dArr(arr, 4);
        dArr.Resize(2);

        DynamicArray newArr(dArr);

        newArr.Set(1, 300);

        for (int i=0; i<newArr.GetLen(); ++i)
            cout << newArr.Get(i) << endl;

        for (int i=0; i<dArr.GetLen(); ++i)
            cout << dArr.Get(i) << endl;

        */
        int container[5] = {100, 101, 102, 103, 104};

        LinkedList<int> obj;
        LinkedList<int> testObj(container, 5);

        cout << "Iterating over testObj elements: " << endl << endl;

        for (int i=0; i<5; ++i)
            cout << testObj.Get(i) << endl;

        cout << endl << "end of iteration..." << endl << endl;

        obj.PushBack(5);
        obj.PushBack(7);

        int index = 1;

        cout << "Size: " << obj.GetSize() << endl;
        cout << "Get node [" << index << "]: " << obj.Get(index) << endl;
        cout << "First: " << obj.GetFirst() << endl;
        cout << "Last: " << obj.GetLast() << endl;

        LinkedList<int> copyOfAnother(testObj);

        cout << "testObj size: " << testObj.GetSize() << endl;

        cout << copyOfAnother.GetSize() << endl;
        cout << "Iterating over copyOfAnother elements: " << endl << endl;


        for (int i=0; i<5; ++i)
            cout << copyOfAnother.Get(i) << endl;

        cout << endl << "end of iteration..." << endl << endl;

        cout << "Insertion attempt" << endl;

        copyOfAnother.Insert(500, 5);

        cout << "Iterating over copyOfAnother elements: " << endl << endl;

        for (int i=0; i<6; ++i)
            cout << copyOfAnother.Get(i) << endl;

        cout << endl << "end of iteration..." << endl << endl;

        LinkedList<int> li;
        li.Insert(907, 0);

        cout << li.Get(0) << endl;


    }
    catch(DynamicArrayException<int> & ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
