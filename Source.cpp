#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <list>

class Solution {
public:
  std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> sln;
    sln.reserve(numCourses);

    std::vector<int> dependenciesCount(numCourses, 0);
    std::vector<std::vector<int>> dependentCourses(numCourses, std::vector<int>());

    std::list<int> depsFreeCourses;

    // create datastructures
    for (const auto& deps : prerequisites) {
      dependenciesCount[deps[0]]++;
      dependentCourses[deps[1]].push_back(deps[0]);
    }

    // find starting points
    for (int i = 0; i < numCourses; i++)
      if (dependenciesCount[i] == 0) {
        depsFreeCourses.push_back(i);
      }

    // complete courses
    while (sln.size() != numCourses) {
      std::list<int> newDepsFreeCourses;

      for (auto finishedCourse : depsFreeCourses) {
        sln.push_back(finishedCourse);

        for (auto course : dependentCourses[finishedCourse]) {
          dependenciesCount[course]--;
          if (dependenciesCount[course] == 0)
            newDepsFreeCourses.push_back(course);
        }
      }

      depsFreeCourses = std::move(newDepsFreeCourses);

      if (sln.size() != numCourses && depsFreeCourses.size() == 0)
        return std::vector<int>();
    }

    return sln;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  int x;
  int sqrt;


  Test(int x, int sqrt)
    : id(Test::TestsCount++), x(x), sqrt(sqrt) {}

};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  int numCourses{ 0 };
  std::vector<std::vector<int>> deps;

  std::ifstream inputFile("210.input.txt");
  inputFile >> numCourses;

  int depsCount{ 0 };
  inputFile >> depsCount;
  deps.reserve(depsCount);

  for (int i = 0; i < depsCount; i++) {
    int a, b;
    inputFile >> a >> b;
    deps.push_back({ a, b });
  }

  std::cout << sln.findOrder(numCourses, deps) << '\n';

  // std::cout << deps << '\n';

  // Test tests[] = {
  //   Test(1, 1),
  //   Test(0, 0),
  //   Test(4, 2),
  //   Test(25, 5),
  //   Test(8, 2)
  // };

  // for (const auto& test : tests) {
  //   if (sln.mySqrt(test.x) == test.sqrt) {
  //     std::cout << ccolor::lime << test.id << ". Passed!\n";
  //   }
  //   else {
  //     std::cout << ccolor::dark_red << test.id << ". Failed!\n";
  //   }
  // }

  return 0;
}