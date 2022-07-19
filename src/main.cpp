#include <iostream>
using std::cout;

class main {
 private:
  /* data */
 public:
  main(/* args */) = default;
  ~main() = default;
};

auto func(int oka, int notok) -> float {
  return static_cast<float>(oka + notok);
}

auto main(/* int argc, char const *argv[] */) -> int {
  cout << "Hello World\n";
  int count = 100;
  if (count > 100) {
    cout << "count\n";
  } else {
    cout << "count1\n";
  }
  int *abc = &count;
  cout << *abc << '\n';
  func(*abc, *abc);
  // sdfsdfasdfasodif

  return 0;
}
