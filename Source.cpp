#include "Console.hpp"

class Solution {
public:
  int smallestRepunitDivByK(int k) {
    long long  sum = 1;

    for (int i = 1; i <= k; i++) {
      if (sum % k == 0)
        return i;

      sum = (sum * 10 + 1) % k;
    }

    return -1;
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
   Test(1, 1),
   Test(2, -1),
   Test(3, 3),
  };

  for (const auto& test : tests) {
    if (sln.smallestRepunitDivByK(test.input) == test.output) {
      console.reset().type("Test", test.id).color(ccolor::dark_green).sep("")
        .log("Passed", ccolor::dark_gray, '!').reset();
    }
    else {
      console.reset().type("Test", test.id).color(ccolor::dark_red).sep("")
        .log("Failed", ccolor::dark_gray, '!').reset();
    }
  }

  return 0;
}
