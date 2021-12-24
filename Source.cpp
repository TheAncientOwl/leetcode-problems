#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>
#include <vector>
#include <array>
#include <set>

class Solution {
public:
  std::vector<std::vector<int>> merge(const std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> sln;

    const int MAX_END_VALUE = 10000;
    std::array<int, MAX_END_VALUE + 1> xAxis{};
    std::set<int> oneBoundInterval;

    int begin = intervals[0][0];
    int end = intervals[0][0];

    for (const auto& interval : intervals) {
      if (interval[0] == interval[1])
        oneBoundInterval.insert(interval[0]);
      else {
        xAxis[interval[0]]++;
        xAxis[interval[1]]--;
      }

      begin = std::min(begin, interval[0]);
      end = std::max(end, interval[1]);
    }

    int start = begin;
    int controlSum = 0;
    const auto ONE_BOUND_INTERVAL_END = oneBoundInterval.end();
    for (int coord = begin; coord <= end; coord++) {
      if (xAxis[coord] == 0) {
        if (controlSum == 0)
          if (auto it = oneBoundInterval.find(coord); it != ONE_BOUND_INTERVAL_END)
            sln.push_back({ *it, *it });
        continue;
      }

      if (controlSum == 0) {
        start = coord;
        controlSum += xAxis[coord];
      }
      else {
        controlSum += xAxis[coord];
        if (controlSum == 0) {
          sln.push_back({ start, coord });
        }
      }
    }

    return sln;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  std::vector<std::vector<int>> input;
  std::vector<std::vector<int>> output;

  Test(std::vector<std::vector<int>> input, std::vector<std::vector<int>> output)
    : id(Test::TestsCount++), input(input), output(output) {}

};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({{1,3}, {2,6}, {8,10}, {15,18}}, {{1,6}, {8, 10}, {15, 18}}),
    Test({{1,4}, {4,5}}, {{1,5}}),
    Test({{1,4}, {1,5}}, {{1,5}}),
    Test({{1,4}, {0,0}}, {{0,0}, {1,4}}),
    Test({{1,4}, {0,0}, {3,3}, {5,5}}, {{0,0}, {1,4}, {5,5}}),
    Test({{2,3}, {5,5}, {2,2}, {3,4}, {3,4}}, {{2,4}, {5,5}}),
  };

  for (auto& test : tests) {
    if (sln.merge(test.input) == test.output) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}