#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) const {
    int sum = 0;
    std::vector<int> indices;

    for (int i = 0, size = nums.size(); i < size; i++) {
      if (nums[i] + sum > target)
        break;

      sum += nums[i];
      indices.push_back(i);
    }

    return indices;
  }
};

struct Test {
  int target;
  std::vector<int> nums;
  std::vector<int> answer;

  Test(int target, std::vector<int> nums, std::vector<int> answer) : target(target), nums(nums), answer(answer) {}
};

int main() {
  std::cout << "IDK\n";
  Solution sln;

  Test tests[] = {
    Test(9, {2, 7, 11, 15}, {0, 1}),
    Test(6, {3, 2, 4}, {1, 2}),
    Test(6, {3, 3}, {0, 1}),
  };

  for (const auto& test : tests) {
    if (sln.twoSum(test.nums, test.target) == test.answer) {
      std::cout << ccolor::green << "Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << "Failed!\n";
    }
  }

  return 0;
}