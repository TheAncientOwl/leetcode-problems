#include "Console.hpp"
#include "other_ostreams.hpp"

#include <string_view>
#include <string>
#include <array>

class Solution {
public:
  int lengthOfLongestSubstring(std::string_view s) {
    int max = 0;
    int windowBegin = 0;

    std::array<int, 256> lastIndex;
    lastIndex.fill(-1);

    for (int windowEnd = 0, length = s.length(); windowEnd < length; windowEnd++) {
      windowBegin = std::max(windowBegin, lastIndex[s[windowEnd]] + 1);

      max = std::max(max, windowEnd - windowBegin + 1);

      lastIndex[s[windowEnd]] = windowEnd;
    }

    return max;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::string input;
  int output;

  Test(std::string input, int output)
    : id(Test::TestsCount++), input(input), output(output) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
   Test("abcabcbb", 3),
   Test("bbbbb", 1),
   Test("pwwkew", 3),
   Test("", 0),
   Test("qqqqqqwert", 5),
   Test("dvdf", 3),
  };

  for (const auto& test : tests) {
    if (sln.lengthOfLongestSubstring(test.input) == test.output) {
      console.reset().type("Test", test.id).color(ccolor::dark_green).sep("")
        .log("Passed", ccolor::dark_gray, '!').reset();
    }
    else {
      console.reset().type("Test", test.id).color(ccolor::dark_red).sep("")
        .log("Failed", ccolor::dark_gray, '!').reset();
    }
  }

  return 0;
}
