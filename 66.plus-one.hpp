#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

/**
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * Increment the large integer by one and return the resulting array of digits.
 *
 * Example 1:
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * Incrementing by one gives 123 + 1 = 124.
 * Thus, the result should be [1,2,4].
 *
 * Example 2:
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 *
 * Example 3:
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 *
 * Constraints:
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits does not contain any leading 0's.
*/

class Solution {
public:
  std::vector<int> plusOne(const std::vector<int>& digits) {
    std::vector<int> copy = digits;

    int index = copy.size() - 1;

    if (copy.back() != 9) {
      copy[index]++;
    }
    else {
      bool carry = true;
      while (carry == true && index >= 0) {
        if (copy[index] == 9) {
          carry = true;
          copy[index] = 0;
          index--;
        }
        else {
          if (carry) copy[index]++;
          carry = false;
        }
      }

      if (carry)
        copy.insert(copy.begin(), 1);
    }

    return copy;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<int> digits;
  std::vector<int> plusOne;

  Test(std::vector<int> digits, std::vector<int> plusOne)
    : id(Test::TestsCount++), digits(digits), plusOne(plusOne) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({1, 2, 3}, {1, 2, 4}),
    Test({9}, {1, 0}),
    Test({1, 2, 3, 9}, {1, 2, 4, 0}),
    Test({9, 9, 9}, {1, 0, 0, 0})
  };

  for (const auto& test : tests) {
    if (sln.plusOne(test.digits) == test.plusOne) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}