#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
  stack<int> mStack;
  stack<int> stack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
      stack.push(x);
      if(mStack.empty()) {
        mStack.push(x); 
      } else {
        if(mStack.top() >= x) {
          mStack.push(x);
        }
      }
    }
    
    void pop() {
      int temp = stack.top();
      stack.pop();
      if(temp == mStack.top()) {
        mStack.pop();
      }
    }
    
    int top() {
      if(stack.empty()) {
        return -1;
      }
      return stack.top();
    }
    
    int getMin() {
      return mStack.top();
    }
};

int main() {
  MinStack *minStack = new MinStack();
  minStack->push(0);
  minStack->push(1);
  minStack->push(0);
  int t = minStack->getMin();
  cout << t << endl;
  minStack->pop();
  t = minStack->top();
  cout << t << endl;
  t = minStack->getMin();
  cout << t << endl;
  return 0;
}
