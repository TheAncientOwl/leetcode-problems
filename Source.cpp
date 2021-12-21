#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

class Solution {
public:
  int removeElement(std::vector<int>& nums, int val) {
    if (nums.size() == 0)
      return 0;

    int newSize = 0;
    for (int current = 0, size = nums.size(); current < size; current++) {
      if (nums[current] != val)
        nums[newSize++] = nums[current];
    }

    return newSize;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<int> value;
  std::vector<int> answer;
  int element;

  Test(std::vector<int> value, std::vector<int> answer, int element)
    : id(Test::TestsCount++), value(value), answer(answer), element(element) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({3, 2, 2, 3}, {2, 2}, 3),
    Test({0, 1, 2, 2, 3, 0, 4, 2}, {0, 1, 3, 0, 4}, 2),
    Test({0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}, 5),
    Test({0, 1, 2, 3, 4, 4, 4}, {0, 1, 2, 3}, 4),
    Test({0, 1, 2, 2, 2, 2, 3, 4}, {0, 1, 3, 4}, 2),
    Test({0, 0, 1, 2, 3, 4}, {1, 2, 3, 4}, 0),
  };

  for (auto& test : tests) {
    int newSize = sln.removeElement(test.value, test.element);

    if (newSize == test.answer.size()) {
      bool ok = true;
      for (int i = 0; i < newSize; i++) {
        if (test.answer[i] != test.value[i]) {
          ok = false;
          break;
        }
      }

      if (ok)
        std::cout << ccolor::green << test.id << ". Passed!\n";
      else
        std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}