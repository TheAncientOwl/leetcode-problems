#include "ConsoleColorOutput.hpp"
#include "ListNode.hpp"

#include <iostream>
#include <string>

/**
 * Given two binary strings a and b, return their sum as a binary string.
 *
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 *
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 *
 * Constraints:
 * 1 <= a.length, b.length <= 104
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
  std::string addBinary(std::string a, std::string b) {
    std::string res;
    res.reserve(std::max(a.length(), b.length()));

    int i = a.size() - 1;
    int j = b.size() - 1;
    int sum = 0;
    int carry = 0;

    while (i >= 0 || j >= 0) {
      sum = carry;
      if (i >= 0) sum += a[i--] - '0';
      if (j >= 0) sum += b[j--] - '0';
      res += std::to_string(sum % 2);

      carry = sum / 2;
    }

    if (carry != 0) res += '1';

    std::reverse(res.begin(), res.end());

    return res;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::string a;
  std::string b;
  std::string sum;


  Test(std::string a, std::string b, std::string sum)
    : id(Test::TestsCount++), a(a), b(b), sum(sum) {}

};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test("11", "1", "100"),
    Test("1010", "1011", "10101"),
  };

  for (const auto& test : tests) {
    if (sln.addBinary(test.a, test.b) == test.sum) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}