#include "cmake_init_lib/print_greeting.h"

#include <gtest/gtest.h>

#include "cmake_init_lib.h"

// Demonstrate some basic assertions.
TEST(PrintGreetingsLibTests, PrintGreeting) {
  // Make an assertion or test fail
  cmake_init::cmake_init_lib::PrintGreeting print_greeting;
  ASSERT_EQ(print_greeting.Print(), true);
}
