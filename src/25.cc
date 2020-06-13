#include <iostream>
#include "header.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode *temp = nullptr;
    while(temp != tail) {
      ListNode *next = head->next;
      head->next = temp;
      temp = head;
      head = next;
    }
    return temp;
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head) {
      return nullptr;
    }
    ListNode *start = head;
    ListNode *connect = nullptr;
    while(start) {
      int count = 0;
      ListNode *end = start;
      while(++count != k) {
        end = end->next;
        if(!end) {
          return head;
        }
      }

      ListNode *nextHead = end->next;

      ListNode *reverseHead = reverse(start, end);

      if(connect) {
        connect->next = reverseHead;
      } else {
        head = reverseHead;
      }

      start->next = nextHead;
      connect = start;
      start = nextHead;
    }
    return head;
  }
};

int main() {
  Solution s;
  ListNode *n0 = new ListNode(1);
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(3);
  ListNode *n3 = new ListNode(4);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  ListNode *temp = s.reverse(n0, n2);
  while(temp) {
    cout << temp->val << ", ";
    temp = temp->next;
  }
  cout << endl;
  return 0;
}