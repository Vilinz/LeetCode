#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head, *result = head, *next = nullptr;
    while(current) {
      next = current->next;
      if(next == nullptr) {
        break;
      }
      if(current-> val == next->val) {
        current->next = next->next;
      } else {
        current = current->next;
      }
    }
    return head;
  }
};

int main() {
  ListNode* n0 = new ListNode(1);
  ListNode* n1 = new ListNode(1);
  ListNode* n2 = new ListNode(2);
  ListNode* n3 = new ListNode(3);
  ListNode* n4 = new ListNode(3);
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  Solution s;
  n0 = s.deleteDuplicates(n0);
  while(n0) {
    cout << n0->val << endl;
    n0 = n0->next;
  }
  return 0;
}