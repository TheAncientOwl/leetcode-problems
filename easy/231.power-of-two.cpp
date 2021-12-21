#include <iostream>

/**
 * Given an integer n, return true if it is a power of two.Otherwise, return false.
 * An integer n is a power of two, if there exists an integer x such that n == 2x
 *
 * Example 1:
 *  Input: n = 1
 *  Output: true
 *  Explanation: 20 = 1
 *
 * Example 2:
 *  Input: n = 16
 *  Output: true
 *  Explanation: 24 = 16
 *
 * Example 3:
 *  Input: n = 3
 *  Output: false
 *
 * Constraints:
 *  -231 <= n <= 231 - 1
*/

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
