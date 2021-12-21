#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

// Implementation using KMP algorithm
class Solution {
private:
  std::vector<int> computeLPS(std::string_view pattern) {
    std::vector<int> lps = std::vector<int>(pattern.length(), 0);

    int index = 0;
    for (int i = 1; i < pattern.length();) {
      if (pattern[i] == pattern[index]) {
        lps[i] = index + 1;
        index++;
        i++;
      }
      else {
        if (index != 0)
          index = lps[index - 1];
        else {
          lps[i] = 0;
          i++;
        }
      }
    }

    return lps;
  }

public:
  int strStr(std::string_view text, std::string_view pattern) {
    if (pattern.empty()) return 0;

    auto lps = computeLPS(pattern);
    int i = 0;
    int j = 0;
    while (i < text.length() && j < pattern.length()) {
      if (text[i] == pattern[j]) {
        i++;
        j++;
      }
      else {
        if (j != 0)
          j = lps[j - 1];
        else
          i++;
      }
    }

    if (j == pattern.size()) {
      return i - pattern.size();
    }

    return -1;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::string text;
  std::string pattern;
  int indexOf;

  Test(std::string text, std::string pattern, int indexOf)
    : id(Test::TestsCount++), text(text), pattern(pattern), indexOf(indexOf) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test("hello", "ll", 2),
    Test("aaaaa", "bba", -1),
    Test("", "", 0),
  };

  for (const auto& test : tests) {
    if (sln.strStr(test.text, test.pattern) == test.indexOf) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}