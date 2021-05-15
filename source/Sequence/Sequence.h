#ifndef SEQUENCE_H
#define SEQUENCE_H

template<class T>
class Sequence
{
public:
    // == overload
    // assign overload
    virtual T & operator[](int index) = 0;

    virtual int length() = 0;
    virtual int size() = 0;

    virtual void push_back(T data) = 0;
    virtual void push_front(T data) = 0;
    virtual T pop_back() = 0;
    virtual T get(int index) = 0;
    virtual void set(T data, int index) = 0;
    virtual void insert(T data, int index) = 0;
};




#endif // SEQUENCE_H
