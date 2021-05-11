#ifndef STRING_ARR_H
#define STRING_ARR_H

#include "StringArrException.h"

class StringArr : public ArraySequence<char>
{
public:

    StringArr()
    {

    }

    StringArr(char* items, int len)
    : ArraySequence(items, len)
    {

    }

    StringArr(int capacity)
    : ArraySequence(capacity)
    {

    }

    StringArr(DynamicArray<char> & dynamicArray)
    : ArraySequence(dynamicArray)
    {

    }

    StringArr* substr(int iStart, int iEnd)
    {
        if (iStart < 0 || iEnd < 0 || (iStart > iEnd))
            throw StringArrException("IndexOutOfRange");

        int size = iEnd-iStart+1;

        char items[size];

        for (int i=0; i<size; ++i)
            items[i] = get(iStart+i);

        return new StringArr(items, size);
    }

    StringArr* match(StringArr string)
    {
        StringArr* table = (StringArr*)malloc(sizeof(StringArr));

        int count = 1;
        for (int i=string.size()-1; i<size(); ++i)
        {
            ++count;
            if (*substr(i-string.size()+1, i) == string)
                table = realloc(table, sizeof(StringArr)*(count));
        }

        return table;
    }

};

#endif // STRING_ARR_H
