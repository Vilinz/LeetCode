#include <iostream>
#include "header.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int count = 0;
    ListNode *pA = headA, *pB = headB;
    if(pA == nullptr || pB == nullptr) {
      return nullptr;
    }
    while(pA || pB) {
      if(pA == pB) {
        return pA;
      }
      if(pA == nullptr) {
        pA = headB;
      } else {
        pA = pA->next;
      }

      if(pB == nullptr) {
        pB = headA;
      } else {
        pB = pB->next;
      }
    }
    return nullptr;
  }
};

int main() {
  ListNode *a1 = new ListNode(1);
  ListNode *a2 = new ListNode(2);
  ListNode *b1 = new ListNode(3);
  ListNode *b2 = new ListNode(4);
  ListNode *b3 = new ListNode(5);
  ListNode *c1 = new ListNode(6);
  ListNode *c2 = new ListNode(7);
  ListNode *c3 = new ListNode(8);
  a1->next = a2;
  a2->next = c1;
  c1->next = c2;
  c2->next = c3;
  b1->next = b2;
  b2->next = b3;
  b3->next = c1;
  Solution s;
  ListNode *t = s.getIntersectionNode(a1, b1);
  cout << t->val << endl;
  return 0;
}