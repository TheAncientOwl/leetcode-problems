#include "LeetList.hpp"

LeetList::LeetList() : m_Head(nullptr), m_Tail(nullptr) {
}

LeetList::LeetList(const std::vector<int>& values) {
  m_Head = nullptr;
  m_Tail = nullptr;

  for (auto val : values)
    this->push_back(val);
}

LeetList::LeetList(const LeetList& other) {
  m_Head = nullptr;
  m_Tail = nullptr;

  ListNode* it = other.m_Head;
  while (it != nullptr) {
    this->push_back(it->val);
    it = it->next;
  }
}

LeetList::LeetList(LeetList&& other) noexcept {
  m_Head = other.m_Head;
  m_Tail = other.m_Tail;

  other.m_Head = nullptr;
  other.m_Tail = nullptr;
}

LeetList& LeetList::operator=(const LeetList& other) {
  if (this == &other)
    return*this;

  this->clear();

  ListNode* it = other.m_Head;
  while (it != nullptr) {
    this->push_back(it->val);
    it = it->next;
  }

  return *this;
}

LeetList& LeetList::operator=(LeetList&& other) noexcept {
  if (this == &other)
    return*this;

  this->clear();

  m_Head = other.m_Head;
  m_Tail = other.m_Tail;

  other.m_Head = nullptr;
  other.m_Tail = nullptr;

  return *this;
}

LeetList::~LeetList() {
  this->clear();
}

ListNode* LeetList::head() {
  return m_Head;
}

void LeetList::clear() {
  while (!this->empty())
    this->pop_back();

  m_Head = nullptr;
  m_Tail = nullptr;
}

void LeetList::push_back(int value) {
  ListNode* newNode = new ListNode(value);
  if (m_Head == nullptr) {
    m_Head = newNode;
    m_Tail = newNode;
    return;
  }

  m_Tail->next = newNode;
  m_Tail = newNode;
}

void LeetList::pop_back() {
  ListNode* dummy = m_Head;
  while (dummy->next != m_Tail)
    dummy = dummy->next;

  dummy->next = nullptr;
  delete m_Tail;
  m_Tail = dummy;
}

bool LeetList::empty() const {
  return m_Head == nullptr;
}

bool LeetList::operator==(const LeetList& rhs) const {
  ListNode* it1 = m_Head;
  ListNode* it2 = rhs.m_Head;

  while (it1 != nullptr && it2 != nullptr) {
    if (it1->val != it2->val)
      return false;

    it1 = it1->next;
    it2 = it2->next;
  }

  return true;
}