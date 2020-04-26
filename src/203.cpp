#include <iostream>
#include "header.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *currentNode = new ListNode(0);
    currentNode->next = head;
    ListNode *re = currentNode;
    while(currentNode->next) {
      if(currentNode->next->val == val) {
        ListNode *temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        delete temp;
      } else {
        currentNode = currentNode->next;
      }
    }
    return re->next;
  }
};

int main() {
  Solution s;
  ListNode *n0 = new ListNode(1);
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(3);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  ListNode *l = s.removeElements(n0, 1);
  while(l) {
    cout << l->val << ", ";
    l = l->next;
  }
  cout << endl;
  return 0;
}