#pragma once
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LeetList {
private:
  ListNode* m_Head;
  ListNode* m_Tail;

public:
  LeetList();
  LeetList(const std::vector<int>& values);
  LeetList(const LeetList& other);
  LeetList(LeetList&& other) noexcept;
  LeetList& operator=(const LeetList& other);
  LeetList& operator=(LeetList&& other) noexcept;
  ~LeetList();

  ListNode* head();
  void push_back(int value);
  void pop_back();
  void clear();
  bool empty() const;
  bool operator==(const LeetList& rhs) const;
};
