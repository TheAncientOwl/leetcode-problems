#include "Console.hpp"

/**
 * Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.
 * Return the length of n. If there is no such n, return -1.
 * Note: n may not fit in a 64-bit signed integer.
 *
 * Example 1:
 * Input: k = 1
 * Output: 1
 * Explanation: The smallest answer is n = 1, which has length 1.
 *
 * Example 2:
 * Input: k = 2
 * Output: -1
 * Explanation: There is no such positive integer n divisible by 2.
 *
 * Example 3:
 * Input: k = 3
 * Output: 3
 * Explanation: The smallest answer is n = 111, which has length 3.
 *
 * Constraints:
 * 1 <= k <= 105
*/

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
