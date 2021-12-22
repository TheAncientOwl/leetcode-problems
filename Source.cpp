#include "ConsoleColorOutput.hpp"

#include <iostream>
#include <vector>

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