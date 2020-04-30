#include <iostream>
#include "header.h"

class MyQueue {
private:
  stack<int> s1;
  stack<int> s2;
public:
  /** Initialize your data structure here. */
  MyQueue() {

  }
  
  /** Push element x to the back of queue. */
  void push(int x) {
    while(!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    s1.push(x);
    while(!s2.empty()) {
      s1.push(s2.top());
      s2.pop();
    }
  }
  
  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int val = s1.top();
    s1.pop();
    return val;
  }
  
  /** Get the front element. */
  int peek() {
    return s1.top();
  }
  
  /** Returns whether the queue is empty. */
  bool empty() {
    return s1.empty();
  }
};

int main() {
  MyQueue* queue = new MyQueue();

  queue->push(1);
  queue->push(2);  
  cout << queue->peek() << endl;
  cout << queue->pop() << endl;   
  cout << queue->empty() << endl;

  return 0;
}