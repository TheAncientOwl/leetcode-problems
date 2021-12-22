#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

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