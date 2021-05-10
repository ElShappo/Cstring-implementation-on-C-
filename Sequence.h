#ifndef SEQUENCE_H
#define SEQUENCE_H

template<class T>
class Sequence
{
public:
    virtual T & operator[](size_t pos) = 0;
    // == overload
    // assign overload

    virtual T capacity() = 0;
    virtual T size() = 0;

    virtual void push_back() = 0;
    virtual T pop_back() = 0;
    virtual T append() = 0;
    //virtual void set() = 0;

    virtual void reserve() = 0;
    virtual void resize() = 0;




};




#endif // SEQUENCE_H
