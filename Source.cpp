#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>

using namespace std::literals::string_view_literals;

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