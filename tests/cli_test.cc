#include "cli.h"

#include <gtest/gtest.h>

#include <vector>

TEST(CLITests, Parse) {
  // When no command line arguments are given
  std::vector<const char *> argv{"Path to executable"};
  ASSERT_EQ(cmake_init::CLI::Parse(1, argv.data()), std::nullopt);

  // When --help command line arguments is given
  argv.emplace_back("--help");
  ASSERT_NE(cmake_init::CLI::Parse(2, argv.data()), std::nullopt);
  argv.pop_back();

  // When -e command line arguments is given
  argv.emplace_back("-e");
  ASSERT_NE(cmake_init::CLI::Parse(2, argv.data()), std::nullopt);
  argv.pop_back();

  // When both command line arguments are given (if --help is given help should
  // print first)
  argv.emplace_back("-v");
  argv.emplace_back("--help");
  ASSERT_NE(cmake_init::CLI::Parse(3, argv.data()), std::nullopt);
}
