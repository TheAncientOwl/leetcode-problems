#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>

using namespace std::literals::string_view_literals;

/**
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *
 * Symbol  Value
 * I        1
 * V        5
 * X        10
 * L        50
 * C        100
 * D        500
 * M        1000
 *
 * For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
 * Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
 * I can be placed before V (5) and X (10) to make 4 and 9.
 * X can be placed before L (50) and C (100) to make 40 and 90.
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer.
 *
 * Example 1:
 * Input: s = "III"
 * Output: 3
 * Explanation: III = 3.
 *
 * Example 2:
 * Input: s = "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 *
 * Example 3:
 * Input: s = "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 * Constraints:
 * 1 <= s.length <= 15
 * s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 * It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/

class Solution {
public:
  int romanToInt(std::string_view s) {
    std::unordered_map<std::string_view, int> romanValues = {
            {"IV"sv, 4}, {"IX"sv, 9}, {"I"sv, 1}, {"V"sv, 5}, {"XL"sv, 40}, {"XC"sv, 90}, {"X"sv, 10},
            {"L"sv, 50}, {"CD"sv, 400}, {"CM"sv, 900}, {"C"sv, 100}, {"D"sv, 500}, {"M"sv, 1000}
    };

    int answer = 0;

    for (int i = 0, length = s.length(); i < length; i++) {
      if (i < length - 1 && romanValues.find(std::string_view(&s[i], 2)) != romanValues.end()) { // check for combination: IV, IX, etc..
        answer += romanValues[std::string_view(&s[i], 2)];
        i++;
      }
      else answer += romanValues[std::string_view(&s[i], 1)];
    }

    return answer;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::string_view value;
  int answer;

  Test(std::string_view value, int answer) : id(Test::TestsCount++), value(value), answer(answer) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test("I"sv, 1),
    Test("V"sv, 5),
    Test("X"sv, 10),
    Test("L"sv, 50),
    Test("C"sv, 100),
    Test("D"sv, 500),
    Test("M"sv, 1000),
    Test("III"sv, 3),
    Test("II"sv, 2),
    Test("IV"sv, 4),
    Test("VIII"sv, 8),
    Test("LVIII"sv, 58),
    Test("XXVII"sv, 27),
    Test("MCMXCIV"sv, 1994)
  };

  for (const auto& test : tests) {
    if (sln.romanToInt(test.value) == test.answer) {
      std::cout << ccolor::green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}