#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <stack>

class Solution {
public:
  bool isValid(std::string_view s) {
    std::stack<char> openParantheses;

    for (char c : s) {
      if (c == '(' || c == '[' || c == '{')
        openParantheses.push(c);
      else {
        if (openParantheses.empty())
          return false;

        char top = openParantheses.top();
        openParantheses.pop();

        if ((top == '(' && c != ')') || (top == '[' && c != ']') || (top == '{' && c != '}'))
          return false;
      }
    }

    if (!openParantheses.empty())
      return false;

    return true;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::string_view value;
  bool answer;

  Test(std::string_view value, bool answer) : id(Test::TestsCount++), value(value), answer(answer) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test("()", true),
    Test("()[]{}", true),
    Test("(]", false),
    Test("([)]", false),
    Test("()(", false),
  };

  for (const auto& test : tests) {
    if (sln.isValid(test.value) == test.answer) {
      std::cout << ccolor::green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}