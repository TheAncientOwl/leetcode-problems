#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>
#include <vector>

/**
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 * The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 *
 * Example 1:
 * Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
 * Output: [1,2,2,3,5,6]
 * Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
 * The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
 *
 * Example 2:
 * Input: nums1 = [1], m = 1, nums2 = [], n = 0
 * Output: [1]
 * Explanation: The arrays we are merging are [1] and [].
 * The result of the merge is [1].
 *
 * Example 3:
 * Input: nums1 = [0], m = 0, nums2 = [1], n = 1
 * Output: [1]
 * Explanation: The arrays we are merging are [] and [1].
 * The result of the merge is [1].
 * Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 *
 * Constraints:
 * nums1.length == m + n
 * nums2.length == n
 * 0 <= m, n <= 200
 * 1 <= m + n <= 200
 * -109 <= nums1[i], nums2[j] <= 109
*/

class Solution {
private:
  void moveRightByOne(std::size_t index, std::size_t size, std::vector<int>& vec) {
    for (std::size_t i = size - 1; i > index; --i) {
      vec[i] = vec[i - 1];
    }
  }

public:
  void merge(std::vector<int>& nums1, std::size_t size1, std::vector<int>& nums2, std::size_t size2) {
    if (size1 == 0) {
      nums1 = nums2;
      return;
    }

    if (size2 == 0)
      return;

    std::size_t it1 = 0;
    std::size_t it2 = 0;

    while (it1 < size1 && it2 < size2) {

      if (nums1[it1] <= nums2[it2]) {
        it1++;
      }
      else {
        size1++;
        this->moveRightByOne(it1, size1, nums1);
        nums1[it1] = nums2[it2];
        it1++;
        it2++;
      }
    }

    if (it2 < size2)
      for (int i = it2, offset = 0; i < size2; i++, offset++)
        nums1[size1 + offset] = nums2[i];
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<int> input;
  std::size_t m;
  std::vector<int> nums2;
  std::size_t n;
  std::vector<int> output;

  Test(std::vector<int> nums1, std::size_t m, std::vector<int> nums2, std::size_t n, std::vector<int> output)
    : id(Test::TestsCount++), input(nums1), m(m), nums2(nums2), n(n), output(output) {}

};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}),
  };

  for (auto& test : tests) {
    sln.merge(test.input, test.m, test.nums2, test.n);

    if (test.input == test.output) {
      std::cout << ccolor::light_green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}