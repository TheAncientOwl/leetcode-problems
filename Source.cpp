#include "Console.hpp"
#include "ListNode.hpp"

#include <iostream>
#include <vector>
using namespace ConsoleColorOutput;

Console console;
std::string(*str)(int) = std::to_string;

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    bool carry = false;

    ListNode* head = new ListNode(l1->val + l2->val);
    ListNode* tail = head;
    if (head->val > 9) {
      carry = true;
      head->val = head->val % 10;
    }

    ListNode* it1 = l1->next;
    ListNode* it2 = l2->next;

    while (it1 && it2) {
      int value = it1->val + it2->val + carry;

      if (value > 9) {
        carry = true;
        value = value % 10;
      }
      else
        carry = false;

      ListNode* newNode = new ListNode(value);
      tail->next = newNode;
      tail = newNode;

      it1 = it1->next;
      it2 = it2->next;
    }

    return head;
  }
};

struct Test {
private:
  static int TestsCount;

public:
  int id;
  ListUtil l1;
  ListUtil l2;
  ListUtil output;

  Test(std::vector<int> l1, std::vector<int> l2, std::vector<int> output)
    : id(Test::TestsCount++), l1(l1), l2(l1), output(output) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
   Test({2,4,3}, {5,6,4}, {7,0,8}),
  };

  for (const auto& test : tests) {
    ListNode* resultHead = sln.addTwoNumbers(test.l1.head, test.l2.head);
    printList(resultHead);

    console.type("Test" + str(test.id));
    if (test.output.equals(resultHead)) {
      console.color(dark_green).log("Passed");
    }
    else {
      console.color(dark_red).log("Failed");
    }
  }

  return 0;
}