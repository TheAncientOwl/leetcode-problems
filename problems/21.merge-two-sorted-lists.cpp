/**
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
 * Return the head of the merged linked list.
*/

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* it1 = list1;
    ListNode* it2 = list2;

    ListNode head = ListNode(0);
    ListNode* tail = &head;

    while (it1 != nullptr && it2 != nullptr) {
      if (it1->val < it2->val) {
        tail->next = it1;
        it1 = it1->next;
      }
      else {
        tail->next = it2;
        it2 = it2->next;
      }

      tail = tail->next;
    }

    if (it1 != nullptr)
      tail->next = it1;

    if (it2 != nullptr)
      tail->next = it2;

    return head.next;
  }
};
