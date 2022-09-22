#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 *
 * Example 1:
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 * Example 2:
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 * Constraints:
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lower-case English letters.
*/

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
      std::cout << ccolor::dark_green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}