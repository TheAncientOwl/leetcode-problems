#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

/**
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
 * A subarray is a contiguous part of an array.
 *
 * Example 1:
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 *
 * Example 2:
 * Input: nums = [1]
 * Output: 1
 *
 * Example 3:
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 *
 * Constraints:
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
*/

class Solution {
public:
  int maxSubArray(const std::vector<int>& nums) {
    int sum = nums[0];
    int max = sum;

    for (int i = 1, size = nums.size(); i < size; i++) {
      if (sum + nums[i] > nums[i])
        sum += nums[i];
      else
        sum = nums[i];

      max = std::max(max, sum);
    }

    return max;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<int> nums;
  int sum;

  Test(std::vector<int> nums, int sum)
    : id(Test::TestsCount++), nums(nums), sum(sum) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6),
    Test({1}, 1),
    Test({5, 4, -1, 7, 8}, 23),
    Test({-1}, -1),
    Test({-4, -5, -1}, -1)
  };

  for (const auto& test : tests) {
    if (sln.maxSubArray(test.nums) == test.sum) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}