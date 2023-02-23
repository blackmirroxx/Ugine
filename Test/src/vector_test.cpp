#include "pch.h"
#include "ugine/vector.h"

TEST(Vector2D, getLength) {
    auto vec = ugine::Vector2D(10 ,15);
    EXPECT_FLOAT_EQ(vec.length(),18.02775);
    vec.set_x(7);
    vec.set_y(2);
    EXPECT_FLOAT_EQ(vec.length(), 7.280109);
}

TEST(Vector2D, AddVectors) {
    auto v_1 = ugine::Vector2D(10 ,15);
    auto v_2 = ugine::Vector2D(7 ,4);
    ugine::Vector2D res = v_1 + v_2;
    EXPECT_EQ(res.get_x(), 17);
    EXPECT_EQ(res.get_y(), 19);
    res += ugine::Vector2D(5,3);
    EXPECT_EQ(res.get_x(), 22);
    EXPECT_EQ(res.get_y(), 22);
}
TEST(Vector2D, MinusVectors) {
    auto v_1 = ugine::Vector2D(10 ,15);
    auto v_2 = ugine::Vector2D(7 ,4);
    ugine::Vector2D res = v_1 - v_2;
    EXPECT_EQ(res.get_x(), 3);
    EXPECT_EQ(res.get_y(), 11);
    res -= ugine::Vector2D(5,3);
    EXPECT_EQ(res.get_x(), -2);
    EXPECT_EQ(res.get_y(), 8);
}

TEST(Vector2D, VectorEquality) {
    auto v_1 = ugine::Vector2D(10 ,15);
    auto v_2 = ugine::Vector2D(10 ,15);
    EXPECT_EQ(v_1, v_2);
    v_2.set_y(3);
    EXPECT_NE(v_1, v_2);
}

TEST(Vector2D,MultiplyByScalar) {
    auto v_1 = ugine::Vector2D(10 ,15);
    ugine::Vector2D res = v_1 * 3;
    EXPECT_EQ(res.get_x() , 30);
    EXPECT_EQ(res.get_y(), 45);
    res *= -1;
    EXPECT_EQ(res.get_x() , -30);
    EXPECT_EQ(res.get_y(), -45);
}

TEST(Vector2D, DivideByScalar) {
    auto v_1 = ugine::Vector2D(10 ,15);
    ugine::Vector2D res = v_1 / 2;
    EXPECT_EQ(res.get_x() , 5);
    EXPECT_EQ(res.get_y(), 7.5);
    res /= 10;
    EXPECT_EQ(res.get_x() , 0.5);
    EXPECT_EQ(res.get_y(), 0.75);
}

TEST(Vector2D, NormalizedVector) {
    auto vec = ugine::Vector2D(10 ,15);
    vec.normalize();
    EXPECT_FLOAT_EQ(vec.get_x(), 0.5547001);
    EXPECT_FLOAT_EQ(vec.get_y(), 0.8320502);
}