#define CATCH_CONFIG_MAIN
#include "vendor/catch.hpp"

#include "DynamicArray.h"
#include "LinkedList.h"

TEST_CASE("1st test")
{
    CHECK(1 == 1);
    //CHECK_NOTHROW();
}

TEST_CASE("2nd test")
{

    CHECK("1" == "1");
}
