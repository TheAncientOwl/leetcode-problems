#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <string>
#include <string_view>

/**
 * Given a string s consisting of some words separated by some number of spaces, return the length of the last word in the string.
 * A word is a maximal substring consisting of non-space characters only.
 *
 * Example 1:
 * Input: s = "Hello World"
 * Output: 5
 * Explanation: The last word is "World" with length 5.
 *
 * Example 2:
 * Input: s = "   fly me   to   the moon  "
 * Output: 4
 * Explanation: The last word is "moon" with length 4.
 *
 * Example 3:
 * Input: s = "luffy is still joyboy"
 * Output: 6
 * Explanation: The last word is "joyboy" with length 6.
 *
 * Constraints:
 * 1 <= s.length <= 104
 * s consists of only English letters and spaces ' '.
 * There will be at least one word in s.
*/

class Solution {
public:
  int lengthOfLastWord(std::string_view str) {
    while (!str.empty() && str.back() == ' ')
      str.remove_suffix(1);

    int i = str.length() - 1;
    while (i >= 0 && str[i] != ' ')
      i--;

    return str.length() - i - 1;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::string str;
  int length;

  Test(std::string str, int length)
    : id(Test::TestsCount++), str(str), length(length) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test("Hello World", 5),
    Test("   fly me   to   the moon  ", 4),
    Test("luffy is still joyboy", 6)
  };

  for (const auto& test : tests) {
    if (sln.lengthOfLastWord(test.str) == test.length) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}