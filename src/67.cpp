#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    if(a.size() < b.size()) {
      string temp = a;
      a = b;
      b = temp;
    }
    int aLen = a.size(), bLen = b.size();
    int carry = 0;
    string result(aLen, '0');
    for(int i = 1; i <= bLen; i++) {
      if((carry == 0 && a[aLen - i] == '1' && b[bLen - i] == '0') || 
          (carry == 0 && a[aLen - i] == '0' && b[bLen - i] == '1') ||
          (carry == 1 && a[aLen - i] == '0' && b[bLen - i] == '0')
        ) {
          result[aLen - i] = '1';
          carry = 0;
      } else if((carry == 0 && a[aLen - i] == '1' && b[bLen - i] == '1') ||
        (carry == 1 && a[aLen - i] == '1' && b[bLen - i] == '0') || 
        (carry == 1 && a[aLen - i] == '0' && b[bLen - i] == '1')) {
        carry = 1;
      } else if(carry == 0 && a[aLen - i] == '0' && b[bLen - i] == '0') {
        carry = 0;
      } else if(carry == 1 && a[aLen - i] == '1' && b[bLen - i] == '1'){
        carry = 1;
        result[aLen - i] = '1';
      }
    }
    int j = aLen - bLen;
    while(j > 0) {
      if(carry == 1 && a[j - 1] == '1') {
        carry = 1;
      } else if(carry == 0 && a[j - 1] == '0') {
        carry = 0;
      } else {
        carry = 0;
        result[j - 1] = '1';
      }
      j--;
    }
    if(carry == 1) {
      return ("1" + result);
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.addBinary("100", "110010") << endl;
  return 0;
}
