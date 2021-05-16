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

        ListSequence<char> obj();
        cout << obj[0] << endl;
        //Print(newTest);

        */

        StringArr test(5);

        test.push_back('h');
        test.push_back('e');
        test.push_back('l');
        test.push_back('l');
        test.push_back('o');

        StringArr cmp(test);

        cout << (test == cmp) << endl;
    }
    catch(DynamicArrayException<int> & ex)
    {
        cout << ex.what() << endl;
    }

    return 0;
}
