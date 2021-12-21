#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>
#include <map>

/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 *
 * Example 1:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 * Example 2:
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 * Example 3:
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 * Constraints:
 * 2 <= nums.length <= 104
 * -109 <= nums[i] <= 109
 * -109 <= target <= 109
 * Only one valid answer exists.
*/

class Solution {
public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) const {
    std::vector<int> sln;

    /**
     * map key->value where
     *   key:   I'm looking for this *key* value.
     *   value: The index where the complement is.
    */
    std::map<int, int> lookingFor;

    for (int i = 0, size = nums.size(); i < size; i++) {
      auto it = lookingFor.find(nums[i]);

      if (it != lookingFor.end()) {
        sln.push_back(it->second);
        sln.push_back(i);
        break;
      }

      lookingFor.insert(std::make_pair(target - nums[i], i));
    }

    return sln;
  }
};

struct Test {
  int id;
  int target;
  std::vector<int> nums;
  std::vector<int> answer;

  Test(int id, int target, std::vector<int> nums, std::vector<int> answer)
    : id(id), target(target), nums(nums), answer(answer) {}
};

int main() {
  Solution sln;

  Test tests[] = {
    Test(1, 9, {2, 7, 11, 15}, {0, 1}),
    Test(2, 6, {3, 2, 4}, {1, 2}),
    Test(3, 6, {3, 3}, {0, 1}),
  };

  for (const auto& test : tests) {
    if (sln.twoSum(test.nums, test.target) == test.answer) {
      std::cout << ccolor::green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}