#include <iostream>

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n == 0)
      return false;

    while (n % 2 == 0)
      n /= 2;

    return n == 1;
  }
};

struct Test {
  const int value;
  const bool answer;

public:
  Test(int value, bool answer) : value(value), answer(answer) {}

};

int main() {
  Solution sln;

  Test tests[] = {
    Test(0, false),
    Test(1, true),
    Test(2, true),
    Test(3, false),
    Test(4, true),
    Test(16, true),
    Test(25, false)
  };

  for (const auto& test : tests) {
    bool answer = sln.isPowerOfTwo(test.value);

    if (answer == test.answer) {
      std::cout << "Passed!\n";
    }
    else {
      std::cout << "\n";
      std::cout << "Failed!\n";
      std::cout << ">> " << test.value << " expected to be " << test.answer << " but found " << answer << "!\n";
      std::cout << "\n";
    }
  }

  return 0;
}
