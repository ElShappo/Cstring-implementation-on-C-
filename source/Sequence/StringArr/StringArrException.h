#ifndef STRING_ARR_EXCEPTION
#define STRING_ARR_EXCEPTION

//#include <exception>

class StringArrException : public std::invalid_argument
{
public:
    StringArrException(const char* ex)
    : invalid_argument(ex)
    {

    }

};

#endif // STRING_ARR_EXCEPTION
