#include "gtest/gtest.h"
#include "../Queue.h"
#include <iostream>

TEST(QueueTest, EmptyTest) {
    Queue q;
    ASSERT_TRUE(q.empty());
    q.enqueue(1);
    ASSERT_FALSE(q.empty());
    q.dequeue();
    ASSERT_TRUE(q.empty());
}

TEST(QueueTest, BasicInsert) {
    Queue q;
    q.enqueue(1);
    ASSERT_TRUE(1 == q.front());
    for(int i = 2; i <= 5; ++i) {
        q.enqueue(i);
    }
    for(int i = 1; i <= 5; ++i) {
        ASSERT_TRUE(i == q.front());
        q.dequeue();
    }
    ASSERT_TRUE(q.empty());
}

TEST(QueueTest, DequeueWhenEmpty) {
    Queue q;
    q.enqueue(1);
    q.dequeue();
    q.dequeue();
    ASSERT_TRUE(q.empty());
}

TEST(QueueTest, DifficultTest) {
    Queue q;
    for(int i = 1; i <= 10; ++i) {
        q.enqueue(i);
    }
    ASSERT_TRUE(1 == q.front());

    for(int i = 1; i <= 5; ++i) {
        q.dequeue();
    }
    ASSERT_TRUE(6 == q.front());

    for(int i = 11; i <= 20; ++i) {
        q.enqueue(i);
    }

    for(int i = 6; i <= 19; ++i) {
        ASSERT_TRUE(i == q.front());
        q.dequeue();
    }

    for(int i = 1; i <= 10; ++i) {
        q.enqueue(i);
    }
    ASSERT_TRUE(20 == q.front());
    q.dequeue();


    for(int i = 1; i <= 10; ++i) {
        ASSERT_TRUE(i == q.front());
        q.dequeue();
    }
    ASSERT_TRUE(q.empty());
}

// massive stress test, not necessary for passing the lab
// will take a couple mins or so to run
// TEST(QueueTest, StressTest) {
//     Queue q;

//     for(int i = 1; i <= 100000; ++i) {
//         q.enqueue(i);
//     }

//     for(int i = 1; i <= 100000; ++i) {
//         ASSERT_TRUE(i == q.front());
//         q.dequeue();
//     }

//     for(int i = 1; i <= 1000000; ++i) {
//         q.enqueue(i);
//     }

//     for(int i = 1; i <= 500000; ++i) {
//         q.dequeue();
//     }

//     for(int i = 1000001; i <= 2000000; ++i) {
//         q.enqueue(i);
//     }

//     for(int i = 500001; i <= 2000000; ++i) {
//         q.dequeue();
//     }

//     ASSERT_TRUE(q.empty());
// }



