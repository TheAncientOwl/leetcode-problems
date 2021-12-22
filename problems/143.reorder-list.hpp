#include "ConsoleColorOutput.hpp"
#include "ListNode.hpp"

#include <iostream>
#include <vector>

/**
 * You are given the head of a singly linked-list. The list can be represented as:
 * L0 → L1 → … → Ln - 1 → Ln
 * Reorder the list to be on the following form:
 *
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes. Only nodes themselves may be changed.
 *
 * Example 1:
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 *
 * Example 2:
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 *
 * Constraints:
 * The number of nodes in the list is in the range [1, 5 * 104].
 * 1 <= Node.val <= 1000
*/

class Solution {
private:
  ListNode* findMidNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while (current != nullptr) {
      next = current->next;
      current->next = prev;

      prev = current;
      current = next;
    }

    head = prev;

    return head;
  }

  ListNode* mergeLists(ListNode* head1, ListNode* head2) {
    ListNode dummy = ListNode(-1);
    ListNode* it = &dummy;

    ListNode* it1 = head1;
    ListNode* it2 = head2;

    while (it1 != nullptr && it2 != nullptr) {
      it->next = it1;
      it1 = it1->next;
      it = it->next;

      it->next = it2;
      it2 = it2->next;
      it = it->next;
    }

    if (it1 != nullptr)
      it->next = it1;

    if (it2 != nullptr)
      it->next = it2;

    return dummy.next;
  }
public:
  void reorderList(ListNode* head) {
    ListNode* l1 = head;

    ListNode* midNode = this->findMidNode(head);
    ListNode* dummy = midNode->next;
    midNode->next = nullptr;

    ListNode* l2 = this->reverseList(dummy);

    head = this->mergeLists(l1, l2);
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  ListUtil input;
  ListUtil output;

  Test(const std::vector<int>& input, const std::vector<int>& output)
    : id(Test::TestsCount++), input(input), output(output) {}

  ~Test() {
    input.clear();
    output.clear();
  }
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
    Test({1, 2, 3, 4}, {1, 4, 2, 3}),
    Test({1, 2, 3, 4, 5}, {1, 5, 2, 4, 3}),
  };

  for (const auto& test : tests) {
    sln.reorderList(test.input.head);
    if (test.output.equals(test.input.head)) {
      std::cout << ccolor::lime << test.id << ". Passed!\n";
    }
    else {
      std::cout << ccolor::dark_red << test.id << ". Failed!\n";
    }
  }

  return 0;
}
