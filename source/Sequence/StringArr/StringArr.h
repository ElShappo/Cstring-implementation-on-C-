#ifndef STRING_ARR_H
#define STRING_ARR_H

#include "StringArrException.h"
#include "../ArraySequence/ArraySequence.h"

template <template<typename> typename C = DynamicArray>
class StringArr : public ArraySequence<char, DynamicArray>
{
public:
    StringArr()
    : ArraySequence()
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

    bool operator ==(const StringArr & array) const { return (*array.array_ == *array_); }
    bool operator !=(const StringArr & array) const { return (*array.array_ != *array_); }
    void operator =(StringArr & array) { *array_ = *array.array_; }

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
            if (*substr(i-string.size()+1, i) == string)
            {
                ++count;
                table[i] = *substr(i-string.size()+1, i);
                realloc(table, sizeof(StringArr)*(count));
            }
        }
        return table;
    }

    StringArr* separate(int iSeparating)
    {
        if (iSeparating < 0 || iSeparating >= size())
            throw StringArrException("IndexOutOfRange");

        if (iSeparating == size()-1)
            return this;

        StringArr* strings = new StringArr(2);

        strings[0] = *substr(0, iSeparating);
        strings[1] = *substr(iSeparating+1, size()-1);

        return strings;
    }
};

#endif // STRING_ARR_H
