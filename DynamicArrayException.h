#ifndef DYNAMIC_ARRAY__EXCEPTIONS_H
#define DYNAMIC_ARRAY__EXCEPTIONS_H

#include <exception>
#include <iostream>

template <class T>
class DynamicArrayException : public std::invalid_argument
{
public:
    DynamicArrayException(const char* ex)
    : invalid_argument(ex)
    {

    }
private:
};

#endif // DYNAMIC_ARRAY__EXCEPTIONS_H
