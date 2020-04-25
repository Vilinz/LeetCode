#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode *n) {
    ListNode *pre = nullptr;
    while(n) {
      ListNode *next = n->next;
      n->next = pre;
      pre = n;
      n = next;
    }
    return pre;
  }
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    ListNode *result = nullptr;
    int carry = 0;
    while(l1 && l2) {
      int sum = l1->val + l2->val + carry;
      carry = (sum >= 10 ? 1 : 0);
      ListNode *temp = new ListNode(sum%10);
      temp->next = result;
      result = temp;
      l1 = l1->next;
      l2 = l2->next;
    }

    while(l1) {
      int sum = l1->val + carry;
      carry = (sum >= 10 ? 1 : 0);
      ListNode *temp = new ListNode(sum%10);
      temp->next = result;
      result = temp;
      l1 = l1->next;
    }

    while(l2) {
      int sum = l2->val + carry;
      carry = (sum >= 10 ? 1 : 0);
      ListNode *temp = new ListNode(sum%10);
      temp->next = result;
      result = temp;
      l2 = l2->next;
    }

    if(carry == 1) {
      ListNode *temp = new ListNode(1);
      temp->next = result;
      result = temp;
    }

    return result == nullptr ? (new ListNode(0)) : result;
  }
};

int main() {
  Solution s;
  ListNode *n1 = new ListNode(7);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(4);
  ListNode *n4 = new ListNode(6);
  ListNode *n5 = new ListNode(5);
  ListNode *n6 = new ListNode(6);
  ListNode *n7 = new ListNode(4);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n5->next = n6;
  n6->next = n7;
  ListNode *r = s.addTwoNumbers(n4, n7);
  while(r) {
    cout << r->val << endl;
    r = r->next;
  }
  return 0;
}