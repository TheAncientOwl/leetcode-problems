#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() == 0)
      return 0;

    int left = 0;
    for (int right = 1, size = nums.size(); right < size; right++) {
      if (nums[left] != nums[right])
        left++;
      nums[left] = nums[right];
    }

    return left + 1;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<int> value;
  std::vector<int> answer;

  Test(std::vector<int> value, std::vector<int> answer) : id(Test::TestsCount++), value(value), answer(answer) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({0, 0, 0, 1, 2, 3, 3, 3, 3, 4, 5, 6, 7, 8}, {0, 1, 2, 3, 4, 5, 6, 7, 8}),
    Test({0, 1, 2, 3}, {0, 1, 2, 3}),
    Test({0, 1, 2, 3, 3, 3}, {0, 1, 2, 3}),
    Test({0, 1, 2, 3, 3}, {0, 1, 2, 3}),
    Test({0, 0, 0, 1, 2, 3, 3}, {0, 1, 2, 3}),
  };

  for (auto& test : tests) {
    int newSize = sln.removeDuplicates(test.value);

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