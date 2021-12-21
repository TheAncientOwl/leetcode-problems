#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

class Solution {
public:
  int searchInsert(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] >= target)
        right = mid - 1;
      else
        left = mid + 1;
    }

    return left;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<int> nums;
  int target;
  int position;

  Test(std::vector<int> nums, int target, int position)
    : id(Test::TestsCount++), nums(nums), target(target), position(position) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({1, 3, 5, 6}, 5, 2),
    Test({1, 3, 5, 6}, 2, 1),
    Test({1, 3, 5, 6}, 7, 4),
    Test({1, 3}, 2, 1),
    Test({1, 3, 5}, 1, 0),
    Test({1}, 1, 0)
  };

  for (const auto& test : tests) {
    if (sln.searchInsert(test.nums, test.target) == test.position) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}