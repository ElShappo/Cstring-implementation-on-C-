#ifndef SEQUENCE_H
#define SEQUENCE_H

template<typename T, template<typename> typename C>
class Sequence
{
public:
    virtual T & operator[](int index) = 0;
    virtual bool operator ==(const C<T> & buffer) const = 0;
    virtual bool operator !=(const C<T> & buffer) const = 0;
    virtual void operator =(C<T> & buffer) = 0;

    virtual int length() = 0;
    virtual int size() = 0;
    virtual void push_back(T data) = 0;
    virtual void push_front(T data) = 0;
    virtual T pop_back() = 0;
    virtual T get(int index) = 0;
    virtual void set(T data, int index) = 0;
    virtual void insert(T data, int index) = 0;
    virtual bool empty() = 0;
};




#endif // SEQUENCE_H
