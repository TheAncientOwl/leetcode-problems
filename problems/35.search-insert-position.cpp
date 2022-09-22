#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

/**
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 * You must write an algorithm with O(log n) runtime complexity.
 *
 * Example 1:
 * Input: nums = [1,3,5,6], target = 5
 * Output: 2
 *
 * Example 2:
 * Input: nums = [1,3,5,6], target = 2
 * Output: 1
 *
 * Example 3:
 * Input: nums = [1,3,5,6], target = 7
 * Output: 4
 *
 * Constraints:
 * 1 <= nums.length <= 104
 * -104 <= nums[i] <= 104
 * nums contains distinct values sorted in ascending order.
 * -104 <= target <= 104
*/

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
      std::cout << ccolor::light_green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}