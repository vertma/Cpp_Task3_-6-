#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Queue.h"
#include <string>

TEST_CASE("Testing basic operations of Queue<int>") {
    Queue<int> q;

    CHECK(q.isEmpty() == true);
    CHECK(q.getSize() == 0);

    SUBCASE("Push and front") {
        q.push(10);
        CHECK(q.isEmpty() == false);
        CHECK(q.getSize() == 1);
        CHECK(q.front() == 10);
    }

    SUBCASE("Pop") {
        q.push(20);
        q.pop();
        CHECK(q.isEmpty() == true);
    }

    SUBCASE("FIFO order with multiple elements") {
        q.push(1);
        q.push(2);
        q.push(3);
        CHECK(q.front() == 1);
        q.pop();
        CHECK(q.front() == 2);
        q.pop();
        CHECK(q.front() == 3);
    }
}

TEST_CASE("Working with different types (int and string)") {
    SUBCASE("Queue for int") {
        Queue<int> intQ;
        intQ.push(100);
        intQ.push(200);
        CHECK(intQ.front() == 100);
        intQ.pop();
        CHECK(intQ.front() == 200);
    }

    SUBCASE("Queue for std::string") {
        Queue<std::string> stringQ;
        stringQ.push("first");
        stringQ.push("second");
        CHECK(stringQ.front() == "first");
        stringQ.pop();
        CHECK(stringQ.front() == "second");
    }
}


TEST_CASE("Exception handling when queue is empty") {
    Queue<double> q;
    CHECK_THROWS_AS(q.front(), const std::runtime_error&);
    CHECK_THROWS_AS(q.pop(), const std::runtime_error&);
}


TEST_CASE("Automatic resizing") {
    Queue<int> q(2);
    q.push(1);
    q.push(2);
    CHECK(q.getSize() == 2);
    CHECK(q.front() == 1);

    q.push(3);
    CHECK(q.getSize() == 3);
    CHECK(q.front() == 1);

    q.pop();
    CHECK(q.front() == 2);
    q.pop();
    CHECK(q.front() == 3);
}


TEST_CASE("Table-driven test for front/pop") {
    int test_data[][3] = {
        {1, 2, 1},
        {5, 5, 5},
        {-1, -2, -1}
    };

    for (const auto& row : test_data) {
        Queue<int> q;
        q.push(row[0]);
        q.push(row[1]);
        CHECK(q.front() == row[2]);
        q.pop();
    }
}