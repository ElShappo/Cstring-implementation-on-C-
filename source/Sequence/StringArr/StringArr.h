#ifndef STRING_ARR_H
#define STRING_ARR_H

#include "StringArrException.h"
#include "../ArraySequence/ArraySequence.h"

class StringArr
{
private:
    ArraySequence<char>* string_;

public:

    StringArr() { string_ = new ArraySequence<char>(); }
    StringArr(char* items, int len) { string_ = new ArraySequence<char>(items, len); }
    StringArr(int capacity) { string_ = new ArraySequence<char>(capacity); }
    StringArr(ArraySequence<char> & arraySequence) { string_ = new ArraySequence<char>(arraySequence); }

    char & operator[](int index) { return (*string_)[index]; }
    int length() { return string_->size(); }
    int size() { return string_->size(); }
    void push_back(char data) { string_->push_back(data); }
    void push_front(char data) { string_->push_front(data); }
    char pop_back() { return string_->pop_back(); }
    char get(int index) { return string_->get(index); }
    void set(char data, int index) { string_->set(data, index); }
    void insert(char data, int index) { string_->insert(data, index); }

    int capacity() { return string_->capacity(); }
    void reserve(int capacity) { string_->reserve(capacity); }
    void resize(int len) { string_->resize(len); }
    void swap(int pos1, int pos2) { string_->swap(pos1, pos2); }
    void shrink_to_fit() { string_->shrink_to_fit(); }

    bool operator ==(StringArr array)
    {
        for (int i=0; i<array.size(); ++i)
        {
            if (array.get(i) != get(i))
                return false;
        }
        return true;
    }

    bool operator !=(StringArr array)
    {
        for (int i=0; i<array.size(); ++i)
        {
            if (array.get(i) == get(i))
                return false;
        }
        return true;
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
