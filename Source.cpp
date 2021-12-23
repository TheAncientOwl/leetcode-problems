#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1)
      return 1;

    if (n == 2)
      return 2;

    unsigned int x = 1;
    unsigned int y = 2;
    unsigned int z = x + y;
    for (int index = 2; index < n; index++) {
      x = y;
      y = z;
      z = x + y;
    }

    return y;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  int input;
  int output;


  Test(int input, int output)
    : id(Test::TestsCount++), input(input), output(output) {}

};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
   Test(2, 2),
   Test(3, 3),
   Test(5, 8),
  };

  for (const auto& test : tests) {
    if (sln.climbStairs(test.input) == test.output) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}