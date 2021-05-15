#include <iostream>

#include "source/DynamicArray/DynamicArray.h"
#include "source/LinkedList/LinkedList.h"
#include "source/Sequence/ArraySequence/ArraySequence.h"

#include "source/Sequence/ListSequence/ListSequence.h"
#include "source/Sequence/Sequence.h"
#include "source/Sequence/StringArr/StringArr.h"
#include "vendor/catch.hpp"

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
void CopyListTest(LinkedList<T> & buffer)
{
    LinkedList<T> obj(buffer);
    PrintData(obj);
}

template <typename T>
void InsertTest(LinkedList<T> list, T data, int index)
{
    cout << "Initial data: " << endl;
    PrintData(list);

    cout << "Inserting " << data << " on " << index << "position: " << endl;
    list.Insert(data, index);

    PrintData(list);
}

template <typename T>
void InsertInEmptyListTest(T data)
{
    LinkedList<T> list;
    InsertTest(list, data, 0);
}

template <typename T>
void InsertAsPushBackTest(T data, int index)
{
    LinkedList<T> list;
    InsertTest(list, data, list.GetSize() );
}

template <typename T>
void InsertAsPushFrontTest(T data, int index)
{
    LinkedList<T> list;
    InsertTest(list, data, 0);
}

template <typename T>
void AppendTest(LinkedList<T> list, LinkedList<T> buffer)
{
    LinkedList<T> res(*list.Append(buffer));
}

template <typename T>
void PrintData(LinkedList<T> obj)
{
    for (int i=0; i<obj.GetSize(); ++i)
        cout << obj.Get(i) << endl;
}

template <class T>
void Print(T object)
{
    for (int i=0; i<object.size(); ++i)
        cout << "(" << i << "): " << object[i] << endl;
}

int main()
{
    try
    {
        /*
        int size = 4;
        double buffer[size] = {-1, 567, 1114, 7985};
        ListSequence<double> test(buffer, size);

        test.push_back(5);
        test.push_front(5678);

        //Print(test);

        int size1 = 4;
        double buffer1[size1] = {2223, 343, 1047, 3064};

        StringArr str;

        str.push_back(5);
        //ArraySequence<double> newTest(buffer1, size1);

        //newTest.push_back(568);
        //newTest.push_back(11117);
        */

        DynamicArray<double> test;

        test.PushBack(678);
        test.PushBack(4564);
        test.PushBack(15226);
        test.PushBack(1);

        DynamicArray<double> cmp(test);

        cmp.PopBack();
        cmp.PopBack();

        for (int i=0; i<2; ++i)
            cout << cmp[i] << endl;

        cout << (cmp != test) << endl;
        //Print(newTest);

        /*
        int size = 4;
        double buffer[size] = {1, 567, 1114, 7985};
        LinkedList<double> test(buffer, size);

        for (int i=0; i<test.GetLen(); ++i)
            cout << test.Get(i) << endl;

        for (int i=0; i<size; ++i)
        {
            // cout << "Hello!" << endl;
            double pop = test.PopBack();
            cout << "Popped data: " << pop << endl;
        }

        //CHECK(test.GetLen() == 0);
        // CHECK(test.GetCapacity() == 4);

        //CHECK_THROWS(test.PopBack());

        for (int i=0; i<7; ++i)
        {
            test.PushBack(i);
            //CHECK(test.Get(i) == i);
        }
        cout << test[2] << endl;

        //CHECK_THROWS(test.Get(7));
        //CHECK_THROWS(test.Get(5678));


        /*
        DynamicArray<double> test;
        test.PushFront(1);
        test.PushFront(2);

        /*for (int i=0; i<10; ++i)
        {
            test.PushFront(i);
        }*/

        /*
        for (int i=0; i<2; ++i)
            cout << test.Get(i) << endl;
        */

        /*
        int size = 4;
        double buffer[size] = {-1, 567, 1114, 7985};
        DynamicArray<double> test(buffer, size);

        test.Insert(404, 2);

        for (int i=0; i<5; ++i)
        {
            cout << test.Get(i) << endl;
        }


        /*
        int size1 = 5;
        int size2 = 3;

        int buff1[size1] = {1, 2, 3, 4, 5};
        int buff2[size2] = {6, 7, 8};

        ItemsListTest(buff1, size1);
        ItemsListTest(buff2, size2);

        LinkedList<int> list1(buff1, size1);
        LinkedList<int> list2(buff2, size2);

        AppendTest(list1, list2);


        // Items

        // AppendTest()





        double arr[4] = {1,3,3,4};

        DynamicArray<double> dArr(arr, 4);
        //dArr.Reserve(2);

        dArr.PushBack(56875);
        dArr.PushBack(346531111);
        // dArr.PopBack();
        // dArr.PopBack();

        DynamicArray newArr(dArr);

        newArr.Set(1, 300);

        for (int i=0; i<newArr.GetLen(); ++i)
            cout << newArr.Get(i) << endl;

        for (int i=0; i<dArr.GetLen(); ++i)
            cout << dArr.Get(i) << endl;

        /*
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

        LinkedList<int>* subList = copyOfAnother.GetSubList(3,4);

        cout << "Iterating over sublist elements: " << endl << endl;

        for (int i=0; i<2; ++i)
            cout << subList->Get(i) << endl;

        cout << endl << "end of iteration..." << endl << endl;

        int buff1[6] = {7,8,9,10,11,12};
        LinkedList<int> obj1(buff1, 6);

        LinkedList<int> obj2(*subList);
        obj2.Append(obj1);

        cout << endl << endl;
        cout << "--------------" << endl << endl;

        for (int i=0; i<obj2.GetSize(); ++i)
            cout << obj2.Get(i) << endl;
        */

        /*
        int buff[5] = {1,2,3,4,5};
        LinkedList<int> list(buff, 5);

        cout << "Start" << endl;

        for (int i=0; i<list.GetSize(); ++i)
            cout << list.Get(i) << endl;

        cout << "End" << endl;

        list.Append(list);

        for (int i=0; i<list.GetSize(); ++i)
            cout << list.Get(i) << endl;
        */


    }
    catch(DynamicArrayException<int> & ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
