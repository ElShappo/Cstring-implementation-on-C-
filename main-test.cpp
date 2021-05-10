#define CATCH_CONFIG_MAIN
#include "vendor/catch.hpp"

#include "DynamicArray.h"
#include "LinkedList.h"

TEST_CASE("Testing GET-method")
{
    int size = 4;
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

TEST_CASE("Testing PushBack-method")
{
    int size = 4;
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

TEST_CASE("Testing Insert-method (1)")
{
    int size = 4;
    double buffer[size] = {-1, 567, 1114, 7985};
    DynamicArray<double> test(buffer, size);

    CHECK_THROWS(test.Insert(404, 5));

    test.Insert(404, 2);

    CHECK(test.Get(0) == -1);
    CHECK(test.Get(1) == 567);
    CHECK(test.Get(2) == 404);
    CHECK(test.Get(3) == 1114);
    CHECK(test.Get(4) == 7985);


}

TEST_CASE("Testing PushFront-method (1)")
{
    int size = 4;
    double buffer[size] = {-1, 567, 1114, 7985};
    DynamicArray<double> test(buffer, size);

    for (int i=0; i<10; ++i)
        test.PushFront(i);

    CHECK(test.GetLen() == 14);
    CHECK(test.GetCapacity() == 14);

    for (int i=0; i<10; i++)
        CHECK(test.Get(i) == 9-i);

    CHECK(test.Get(10) == -1);
    CHECK(test.Get(11) == 567);
    CHECK(test.Get(12) == 1114);
    CHECK(test.Get(13) == 7985);

    CHECK_THROWS(test.Get(166) );
}

TEST_CASE("Testing PushFront-method (2)")
{
    DynamicArray<double> test;

    CHECK_THROWS(test.PopBack());

    for (int i=0; i<10; ++i)
    {
        test.PushFront(i);
        CHECK(test.Get(0) == i);
    }

    CHECK(test.GetLen() == 10);
    CHECK(test.GetCapacity() == 10);

    for (int i=0; i<10; ++i)
    {
        test.PopBack();

        CHECK(test.GetLen() == 9-i);
        CHECK(test.GetCapacity() == 10);
    }
}

TEST_CASE("Testing SET-method (2)")
{
    DynamicArray<double> test;

    for (int i=0; i<10; ++i)
    {
        test.Insert(i, i);
        CHECK (test.Get(i) == i);
    }

    CHECK_THROWS(test.Set(404, -1));
}

TEST_CASE("Testing resistance")
{
    DynamicArray<double> test;

    for (int i=0; i<10; ++i)
        CHECK_THROWS(test.PopBack());
}
