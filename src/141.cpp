#include <iostream>
#include "header.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if(!head || !head->next) {
      return false;
    }
    ListNode *nextHead = head;
    while(nextHead) {
      head = head->next;
      if(!head) {
        return false;
      }
      if(nextHead->next) {
        nextHead = nextHead->next->next;
      } else {
        return false;
      }
      if(head == nextHead) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  ListNode *n0 = new ListNode(1);
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(3);
  ListNode *n3 = new ListNode(4);
  ListNode *n4 = new ListNode(5);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n3;
  cout << s.hasCycle(n0) << endl;
  return 0;
}