#include "cmake_init/print_greeting.h"

#include <gtest/gtest.h>

#include "cmake_init.h"

// Demonstrate some basic assertions.
TEST(PrintGreetingsTests, PrintGreeting) {
  // Make an assertion or test fail
  cmake_init::cmake_init::PrintGreeting print_greeting("Testing");
  ASSERT_EQ(print_greeting.Print(), true);
}
