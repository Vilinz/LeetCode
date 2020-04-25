#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string compressString(string S) {
    string result, temp ="4";
    int count = 0;
    for(int i = 0; i < S.size(); i++) {
      if(i == 0) {
        count = 1;
        temp[0] = S[0];
      }  else {
        if(S[i] == temp[0]) {
          count++;
        } else {
          result += temp[0];
          result += to_string(count);
          temp[0] = S[i];
          count = 1;
        }
      }
      if (i == S.size() - 1) {
        result += temp[0];
        result += to_string(count);
      }
    }
    
    if(result.size() >= S.size()) {
      return S;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.compressString("aabcccccaaa") << endl;
  return 0;
}