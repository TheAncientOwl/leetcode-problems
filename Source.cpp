#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> plusOne(const std::vector<int>& digits) {
    std::vector<int> copy = digits;

    int index = copy.size() - 1;

    if (copy.back() != 9) {
      copy[index]++;
    }
    else {
      bool carry = true;
      while (carry == true && index >= 0) {
        if (copy[index] == 9) {
          carry = true;
          copy[index] = 0;
          index--;
        }
        else {
          if (carry) copy[index]++;
          carry = false;
        }
      }

      if (carry)
        copy.insert(copy.begin(), 1);
    }

    return copy;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<int> digits;
  std::vector<int> plusOne;

  Test(std::vector<int> digits, std::vector<int> plusOne)
    : id(Test::TestsCount++), digits(digits), plusOne(plusOne) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({1, 2, 3}, {1, 2, 4}),
    Test({9}, {1, 0}),
    Test({1, 2, 3, 9}, {1, 2, 4, 0}),
    Test({9, 9, 9}, {1, 0, 0, 0})
  };

  for (const auto& test : tests) {
    if (sln.plusOne(test.digits) == test.plusOne) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}