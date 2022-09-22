#pragma once
#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printList(ListNode* head) {
  for (ListNode* it = head; it != nullptr; it = it->next)
    std::cout << it->val << ' ';
  std::cout << '\n';
}

struct ListUtil {
private:
  ListNode* tail;

public:
  ListNode* head;

  ListUtil() : tail(nullptr), head(nullptr) {}

  ListUtil(const std::vector<int>& values) {
    this->head = nullptr;
    this->tail = nullptr;

    for (auto value : values)
      this->push_back(value);
  }

  void push_back(int x) {
    ListNode* newNode = new ListNode(x);
    if (this->head == nullptr) {
      this->head = newNode;
      this->tail = newNode;
      return;
    }

    this->tail->next = newNode;
    this->tail = newNode;
  }

  void pop_back() {
    if (this->head == this->tail) {
      delete this->head;
      this->head = nullptr;
      this->tail = nullptr;
      return;
    }

    ListNode* dummy = this->head;

    while (dummy != this->tail)
      dummy = dummy->next;

    dummy->next = nullptr;
    delete this->tail;
    this->tail = dummy;
  }

  bool empty() const {
    return this->head == nullptr;
  }

  void clear() {
    while (!this->empty()) {
      this->pop_back();
    }
  }

  void print() const {
    printList(this->head);
  }

  bool equals(ListNode* otherHead) const {
    ListNode* it1 = this->head;
    ListNode* it2 = otherHead;

    while (it1 != nullptr && it2 != nullptr) {
      if (it1->val != it2->val)
        return false;

      it1 = it1->next;
      it2 = it2->next;
    }

    if (it1 != nullptr || it2 != nullptr)
      return false;

    return true;
  }
};
