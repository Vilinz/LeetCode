#include <iostream>
#include "header.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    int count = 0;
    ListNode *temp = head;
    while(temp) {
      count++;
      temp = temp->next;
    }
    temp = head;

    int half = 0;
    stack<int> s;
    while(temp) {
      half++;
      s.push(temp->val);
      temp = temp->next;
      if(half == count/2) {
        break;
      }
    }
    if(count % 2 != 0) {
      temp = temp->next;
    }

    while(temp) {
      int num = s.top();
      s.pop();
      if(num != temp->val) {
        return false;
      }
      temp = temp->next;
    }
    return true;
  }
};

int main() {
  Solution s;
  ListNode *n0 = new ListNode(1);
  ListNode *n1 = new ListNode(2);
  ListNode *n2 = new ListNode(1);
  ListNode *n3 = new ListNode(1);
  n0->next = n1;
  n1->next = n2;
  // n2->next = n3;
  cout << s.isPalindrome(n0) << endl;
  return 0;
}