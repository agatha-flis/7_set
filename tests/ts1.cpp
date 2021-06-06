#include <gtest/gtest.h>
#include "../src/set.h"
#include "../src/set.cpp"

TEST(TS1, insert_int) {
    Set<int> a;
    a.insert(6);
    a.insert(3);
    EXPECT_FALSE(a.empty());
}

TEST(TS1, duplicate) {
    Set<int> b;
    b.insert(6);
    b.insert(3);
    b.insert(3);
    b.insert(3);
    b.insert(5);
    EXPECT_EQ(3,b.size());
}

TEST(TS1, insert_char) {
    Set<char> c;
    c.insert('a');
    c.insert('d');
    c.insert('a');
    EXPECT_EQ(2,c.size());
}

TEST(TS1, isFull_double) {
    Set<double> d;
    d.insert(3.0);
    d.insert(4.0);
    d.insert(5.0);
    d.insert(6.0);
    EXPECT_TRUE(d.isFull());
}

TEST(TS1, isempty) {
    Set<int> e;
    e.insert(3);
    e.clear();
    EXPECT_TRUE(e.empty());
}

