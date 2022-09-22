#include "ConsoleColorOutput.hpp"

/**
 * Given an integer x, return true if x is palindrome integer.
 * An integer is a palindrome when it reads the same backward as forward.
 * For example, 121 is a palindrome while 123 is not.
 *
 * Example 1:
 * Input: x = 121
 * Output: true
 * Explanation: 121 reads as 121 from left to right and from right to left.
 *
 * Example 2:
 * Input: x = -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 *
 * Example 3:
 * Input: x = 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 *
 *
 * Constraints:
 * -231 <= x <= 231 - 1
*/

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
      std::cout << ccolor::dark_green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}