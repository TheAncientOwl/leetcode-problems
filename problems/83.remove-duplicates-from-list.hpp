#include "ConsoleColorOutput.hpp"
#include "ListNode.hpp"

#include <iostream>
#include <vector>

/**
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 * Example 1:
 * Input: head = [1,1,2]
 * Output: [1,2]
 *
 * Example 2:
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
 *
 * Constraints:
 * The number of nodes in the list is in the range [0, 300].
 * -100 <= Node.val <= 100
 * The list is guaranteed to be sorted in ascending order.
*/

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)
      return head;

    ListNode* it = head;

    while (it->next != nullptr) {
      if (it->val == it->next->val) {
        ListNode* dummy = it->next;
        it->next = it->next->next;
        delete dummy;
      }
      else
        it = it->next;
    }

    return head;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  ListUtil input;
  ListUtil output;

  Test(std::vector<int> input, std::vector<int> output)
    : id(Test::TestsCount++), input(input), output(output) {}

};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
   Test({0, 1, 2, 3, 3, 3, 4}, {0, 1, 2, 3, 4}),
   Test({0, 0, 0, 0, 0, 0, 1, 2, 3, 4}, {0, 1, 2, 3, 4}),
   Test({0, 1, 2, 3, 4, 4, 4, 4}, {0, 1, 2, 3, 4}),
   Test({0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 4}, {0, 1, 2, 3, 4}),
  };

  for (const auto& test : tests) {
    sln.deleteDuplicates(test.input.head);

    if (test.output.equals(test.input.head)) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}