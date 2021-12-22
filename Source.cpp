#include "ConsoleColorOutput.hpp"
#include "ListNode.hpp"

#include <iostream>
#include <string>

class Solution {
public:
  int mySqrt(int x) {
    if (x == 1) return 1;

    int left = 1;
    int right = x / 2;

    while (left <= right) {
      long long mid = left + (right - left) / 2;

      long long squared = mid * mid;

      if (squared == x)
        return mid;

      if (squared > x)
        right = mid - 1;
      else
        left = mid + 1;
    }

    return right;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  int x;
  int sqrt;


  Test(int x, int sqrt)
    : id(Test::TestsCount++), x(x), sqrt(sqrt) {}

};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test(1, 1),
    Test(0, 0),
    Test(4, 2),
    Test(25, 5),
    Test(8, 2)
  };

  for (const auto& test : tests) {
    if (sln.mySqrt(test.x) == test.sqrt) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}