#include "ConsoleColorOutput.hpp"
#include "other_ostreams.hpp"

#include <iostream>
#include <fstream>
#include <vector>

/**
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
 * For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 * Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
 *
 * Example 1:
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: [0,1]
 * Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
 *
 * Example 2:
 * Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * Output: [0,2,1,3]
 * Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
 * So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
 *
 * Example 3:
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 *
 * Constraints:
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * All the pairs [ai, bi] are distinct.
*/

class Solution {
public:
  std::vector<int> findOrder(int numCourses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<int> sln;
    sln.reserve(numCourses);

    std::vector<int> dependenciesCount(numCourses, 0);
    std::vector<std::vector<int>> dependentCourses(numCourses, std::vector<int>());

    std::vector<int> depsFreeCourses;

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
      std::vector<int> newDepsFreeCourses;

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

  return 0;
}