#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>
#include <string_view>
#include <vector>
#include <numeric>

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