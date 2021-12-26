#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>
#include <vector>
#include <queue>

class Solution {
private:
  struct Point {
    std::vector<int> bounds;
    double distance;

    Point(int x, int y) {
      bounds.reserve(2);
      bounds.push_back(x);
      bounds.push_back(y);

      this->distance = x * x + y * y;
    }
  };

  struct CompareDistance {
    bool operator()(const Point& p1, const Point& p2) const {
      return p1.distance < p2.distance;
    }
  };

public:
  std::vector<std::vector<int>> kClosest(const std::vector<std::vector<int>>& points, int k) {
    std::vector<std::vector<int>> sln;
    std::priority_queue<Point, std::vector<Point>, CompareDistance> kPoints;

    if (k == 0)
      return sln;

    for (const auto& point : points) {
      kPoints.emplace(point[0], point[1]);

      if (kPoints.size() > k)
        kPoints.pop();
    }

    sln.reserve(k);
    while (!kPoints.empty()) {
      sln.push_back(std::move(kPoints.top().bounds));
      kPoints.pop();
    }

    return sln;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  int k;
  std::vector<std::vector<int>> input;
  std::vector<std::vector<int>> output;

  Test(std::vector<std::vector<int>> input, std::vector<std::vector<int>> output, int k)
    : id(Test::TestsCount++), input(input), output(output), k(k) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
   Test({{1,3}, {-2, 2}}, {{-2, 2}}, 1),
   Test({{3,3}, {5,-1}, {-2,4}}, {{-2,4}, {3, 3}}, 2),
  };

  for (const auto& test : tests) {
    if (sln.kClosest(test.input, test.k) == test.output) {
      std::cout << ccolor::green << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}