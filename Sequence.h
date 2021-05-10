#ifndef SEQUENCE_H
#define SEQUENCE_H

template<class T>
class Sequence
{
public:

    Sequence() {}

    virtual T & operator[](int index) = 0;
    // == overload
    // assign overload

    virtual int length() = 0;

    virtual void push_back(T data) = 0;
    virtual void push_front(T data) = 0;
    virtual T pop_back() = 0;
    virtual void get(int index) = 0;
    virtual void set(T data, int index) = 0;
    virtual void insert(T data, int index) = 0;

    // virtual void reserve() = 0;
    //virtual void resize() = 0;
};




#endif // SEQUENCE_H
