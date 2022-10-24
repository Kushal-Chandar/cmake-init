#include "cmake_init_lib.h"

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(CmakeInitLibTests, SumOfNNaturals) {
  // Make an assertion or test fail
  ASSERT_EQ(cmake_init::sum_of_first_n_naturals(1), 1);
  ASSERT_EQ(cmake_init::sum_of_first_n_naturals(2), 3);
  ASSERT_EQ(cmake_init::sum_of_first_n_naturals(3), 6);
  ASSERT_EQ(cmake_init::sum_of_first_n_naturals(10), 55);
}
