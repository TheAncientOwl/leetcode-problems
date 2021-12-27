#include "Console.hpp"
#include "ListNode.hpp"

#include <vector>

class Solution {
private:
  bool m_Carry;
  ListNode* m_Head;
  ListNode* m_Tail;

private:
  int sumDigits(int digit1, int digit2) {
    int number = digit1 + digit2 + m_Carry;

    if (number > 9) {
      m_Carry = true;
      number = number % 10;
    }
    else m_Carry = false;

    return number;
  }

  void addToTail(int value) {
    ListNode* newNode = new ListNode(value);
    m_Tail->next = newNode;
    m_Tail = newNode;
  }

public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    m_Carry = false;

    m_Head = new ListNode(this->sumDigits(l1->val, l2->val));
    m_Tail = m_Head;

    ListNode* it1 = nullptr;
    ListNode* it2 = nullptr;

    for (it1 = l1->next, it2 = l2->next; it1 && it2; it1 = it1->next, it2 = it2->next)
      this->addToTail(this->sumDigits(it1->val, it2->val));

    for (ListNode* rest = it1 ? it1 : (it2 ? it2 : nullptr); rest; rest = rest->next)
      this->addToTail(this->sumDigits(rest->val, 0));

    if (m_Carry)
      this->addToTail(1);

    return m_Head;
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
    : id(Test::TestsCount++), l1(l1), l2(l2), output(output) {}
};
int Test::TestsCount = 1;

int main() {
  Solution sln;

  Test tests[] = {
   Test({2,4,3}, {5,6,4}, {7,0,8}),
   Test({0}, {0}, {0}),
   Test({9,9,1}, {1}, {0,0,2}),
   Test({9,9,9,9,9,9,9}, {9,9,9,9}, {8,9,9,9,0,0,0,1}),
  };

  for (const auto& test : tests) {
    ListNode* resultHead = sln.addTwoNumbers(test.l1.head, test.l2.head);

    console.reset().sep("").type("Test", test.id);
    if (test.output.equals(resultHead)) {
      console.color(ccolor::dark_green).log("Passed");
    }
    else {
      console.color(ccolor::dark_red).log("Passed");
    }
  }

  return 0;
}
