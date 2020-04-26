#include <iostream>
#include "header.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* merge(ListNode *left, ListNode *right) {
    ListNode *result = new ListNode(0);
    ListNode *loop = result;
    while(left && right) {
      if(left->val <= right->val) {
        loop->next = left;
        left = left->next;
      } else {
        loop->next = right;
        right = right->next;
      }
      loop = loop->next;
    }
    if(left) {
      loop->next = left;
    }
    if(right) {
      loop->next = right;
    }
    return result->next;
  }
  ListNode* mergeNode(vector<ListNode*>& lists, int l, int r) {
    int middle = (l + r)/2;
    if(l > r) {
      return nullptr;
    } else if(l < r) {
      return merge(mergeNode(lists, l, middle), mergeNode(lists, middle + 1, r));
    } else {
      return lists[l];
    }
  }
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *l = mergeNode(lists, 0, lists.size() - 1);
    return l;
  }
};

int main() {
  ListNode *l10 = new ListNode(1);
  ListNode *l11 = new ListNode(4);
  ListNode *l12 = new ListNode(5);
  ListNode *l20 = new ListNode(2);
  ListNode *l21 = new ListNode(3);
  ListNode *l22 = new ListNode(4);
  ListNode *l30 = new ListNode(2);
  ListNode *l31 = new ListNode(6);
  l10->next = l11;
  l11->next = l12;
  l20->next = l21;
  l21->next = l22;
  l30->next = l31;
  Solution s;
  vector<ListNode*> v = {l10,l20,l30};
  ListNode *r = s.mergeKLists(v);
  while(r) {
    cout << r->val << ", ";
    r = r->next;
  }
  cout << endl;
  return 0;
}