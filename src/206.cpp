#include <iostream>
#include "header.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *pre = nullptr, *current = head;
    while(current) {
      ListNode *next = current->next;
      current->next = pre;
      pre = current;
      current = next;
    }
    return pre;
  }
};

int main() {
  ListNode *n0 = new ListNode(1);
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(3);
  ListNode *n3 = new ListNode(4);
  ListNode *n4 = new ListNode(5);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  Solution s;
  ListNode *r = s.reverseList(n0);
  while(r) {
    cout << r->val << ", ";
    r = r->next;
  }
  cout << endl;
  return 0;
}