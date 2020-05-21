#include <iostream>
#include "header.h"

class Solution {
public:
  int compress(vector<char>& chars) {
    char c = chars[0];
    int count = 1;
    int index = 0;
    for(int i = 1; i < chars.size(); i++) {
      if(chars[i] == c) {
        count++;
      } else {
        if(count == 1) {
          chars[index++] = c;
        } else {
          chars[index] = c;
          index++;
          string temp = to_string(count);
          for(int j = 0; j < temp.size(); j++) {
            chars[index] = temp[j];
            index++;
          }
        }
        c = chars[i];
        count = 1;
      }
    }
    if(chars[chars.size() - 1] == c)
      chars[index] = c;
      index++;
      string temp = to_string(count);
      if(count != 1) {
        for(int j = 0; j < temp.size(); j++) {
          chars[index] = temp[j];
          index++;
        }
      }
    return index;
  }
};

int main() {
  vector<char> v = {'a','a','b','b','c','c','c'};
  Solution s;
  cout << s.compress(v) << endl;
  return 0;
}