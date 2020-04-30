#include <iostream>
#include "header.h"

class MyStack {
private:
  queue<int> q;
public:
  /** Initialize your data structure here. */
  MyStack() {

  }
  
  /** Push element x onto stack. */
  void push(int x) {
    q.push(x);
    for(int i = 0; i < q.size() - 1; i++) {
      q.push(q.front());
      q.pop();
    }
  }
  
  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int val = q.front();
    q.pop();
    return val;
  }
  
  /** Get the top element. */
  int top() {
    return q.front();
  }
  
  /** Returns whether the stack is empty. */
  bool empty() {
    return q.empty();
  }
};

int main() {
  MyStack* obj = new MyStack();
  obj->push(1);
  cout << obj->top() << endl;
  cout << obj->empty() << endl;
  return 0;
}