#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>
#include <vector>

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
  std::vector<int> nums1;
  std::size_t m;
  std::vector<int> nums2;
  std::size_t n;
  std::vector<int> output;

  Test(std::vector<int> nums1, std::size_t m, std::vector<int> nums2, std::size_t n, std::vector<int> output)
    : id(Test::TestsCount++), nums1(nums1), m(m), nums2(nums2), n(n), output(output) {}

};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3, {1, 2, 2, 3, 5, 6}),
  };

  for (auto& test : tests) {
    sln.merge(test.nums1, test.m, test.nums2, test.n);

    if (test.nums1 == test.output) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}