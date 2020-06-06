#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool rotateString(string A, string B) {
    if(A == B) {
      return true;
    }
    int ASize = A.size(), BSize = B.size();
    for(int i = 0; i < ASize; i++) {
      if(A[i] == B[0]) {
        if(A.substr(i, ASize - i) + A.substr(0, i) == B) {
          return true;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  cout << s.rotateString("abcde", "cdeab") << endl;
  return 0;
}