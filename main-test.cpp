#define CATCH_CONFIG_MAIN
#include "vendor/catch.hpp"

#include "DynamicArray.h"
#include "LinkedList.h"

TEST_CASE("Testing GET-method")
{
    size_t size = 4;
    double buffer[size] = {1, 567, 1114, 7985};
    DynamicArray<double> test(buffer, size);

    CHECK(test.GetLen() == 4);
    CHECK(test.GetCapacity() == 4);

    test.PushBack(56875);
    test.PushBack(3465311);
    test.PushBack(78);

    CHECK(test.Get(0) == 1);
    CHECK(test.Get(1) == 567);
    CHECK(test.Get(2) == 1114);
    CHECK(test.Get(3) == 7985);
    CHECK(test.Get(4) == 56875);
    CHECK(test.Get(5) == 3465311);
    CHECK(test.Get(6) == 78);

    CHECK(test.GetLen() == 7);
    CHECK(test.GetCapacity() == 7);

    CHECK_THROWS(test.Get(7));
    CHECK_THROWS(test.Get(5678));
}

TEST_CASE("Testing PushBack method")
{
    size_t size = 4;
    double buffer[size] = {1, 567, 1114, 7985};
    DynamicArray<double> test(buffer, size);

    for (int i=0; i<size; ++i)
        test.PopBack();

    CHECK(test.GetLen() == 0);
    CHECK(test.GetCapacity() == 4);

    CHECK_THROWS(test.PopBack());

    for (int i=0; i<7; ++i)
    {
        test.PushBack(i);
        CHECK(test.Get(i) == i);
    }

    CHECK_THROWS(test.Get(7));
    CHECK_THROWS(test.Get(5678));
}

TEST_CASE("2nd test")
{

    CHECK("1" == "1");
}
