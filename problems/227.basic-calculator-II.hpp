#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>
#include <string_view>
#include <vector>
#include <numeric>

/**
 * Given a string s which represents an expression, evaluate this expression and return its value.
 * The integer division should truncate toward zero.
 * You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
 * Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
 *
 * Example 1:
 * Input: s = "3+2*2"
 * Output: 7
 *
 * Example 2:
 * Input: s = " 3/2 "
 * Output: 1
 *
 * Example 3:
 * Input: s = " 3+5 / 2 "
 * Output: 5
 *
 * Constraints:
 * 1 <= s.length <= 3 * 105
 * s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
 * s represents a valid expression.
 * All the integers in the expression are non-negative integers in the range [0, 231 - 1].
 * The answer is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
  int calculate(std::string_view str) {
    using namespace std::literals::string_view_literals;
    constexpr std::string_view OPERATORS = "+-*/"sv;

    std::vector<int> numbers;

    char op = '+';
    int currentNumber = 0;

    for (std::size_t i = 0, length = str.length(); i < length; ++i) {
      if (isdigit(str[i]))
        currentNumber = currentNumber * 10 + (str[i] - '0');

      if (i == length - 1 || OPERATORS.find(str[i]) != std::string_view::npos) {
        switch (op) {
        case '+':
          numbers.push_back(currentNumber);
          break;
        case '-':
          numbers.push_back(currentNumber * (-1));
          break;
        case '*':
          numbers[numbers.size() - 1] = numbers.back() * currentNumber;
          break;
        case '/':
          numbers[numbers.size() - 1] = numbers.back() / currentNumber;
          break;
        }

        currentNumber = 0;
        op = str[i];
      }
    }

    return std::accumulate(numbers.begin(), numbers.end(), 0);
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::string str;
  int output;

  Test(std::string str, int output) : id(Test::TestsCount++), str(str), output(output) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test("3+2*2", 7),
    Test(" 3/2 ", 1),
    Test(" 3+5 / 2 ", 5),
  };

  for (const auto& test : tests) {
    if (sln.calculate(test.str) == test.output) {
      std::cout << ccolor::green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}