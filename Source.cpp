#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    const std::size_t stringsNumber = strs.size();

    for (std::size_t colIndex = 0, arbitraryColsNum = strs[0].length(); colIndex < arbitraryColsNum; colIndex++) {
      for (std::size_t i = 1; i < stringsNumber; i++) {
        if (strs[i].length() < colIndex || strs[i][colIndex] != strs[i - 1][colIndex])
          return std::string(strs[0].data(), colIndex);
      }
    }

    return strs[0];
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<std::string> value;
  std::string answer;

  Test(std::vector<std::string> value, std::string answer) : id(Test::TestsCount++), value(value), answer(answer) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({"flower", "flow", "flight"}, "fl"),
    Test({"dog", "racecar", "car"}, ""),
  };

  for (const auto& test : tests) {
    if (sln.longestCommonPrefix(test.value) == test.answer) {
      std::cout << ccolor::green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}