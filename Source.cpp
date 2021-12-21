#include "ConsoleColorOutput.hpp"

#include <iostream>

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    int copy = x;
    unsigned int reversed = 0;

    while (copy > 0) {
      reversed = reversed * 10 + copy % 10;
      copy /= 10;
    }

    return x == reversed;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  int value;
  bool answer;

  Test(int value, bool answer) : id(Test::TestsCount++), value(value), answer(answer) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test(-121, false),
    Test(5, true),
    Test(0, true),
    Test(121, true),
    Test(234321, false),
    Test(123565321, true),
    Test(123505321, true),
  };

  for (const auto& test : tests) {
    if (sln.isPalindrome(test.value) == test.answer) {
      std::cout << ccolor::green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}