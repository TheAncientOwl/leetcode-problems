#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <stack>

/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: s = "(]"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length <= 104
 * s consists of parentheses only '()[]{}'.
*/

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