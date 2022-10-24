#include <gtest/gtest.h>

// Demonstrate some basic assertions.
// {Header file name}Test, {Test name}
TEST(MainTests, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
  // Expect inequality
  EXPECT_NE(7 * 6, 40);
}
