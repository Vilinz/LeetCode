#include <iostream>
#include "header.h"

class Solution {
public:
  vector<string> findWords(vector<string>& words) {
    map<char, int> m {
      {'q', 1},
      {'w', 1},
      {'e', 1},
      {'r', 1},
      {'t', 1},
      {'y', 1},
      {'u', 1},
      {'i', 1},
      {'o', 1},
      {'p', 1},
      {'a', 2},
      {'s', 2},
      {'d', 2},
      {'f', 2},
      {'g', 2},
      {'h', 2},
      {'j', 2},
      {'k', 2},
      {'l', 2},
      {'z', 3},
      {'x', 3},
      {'c', 3},
      {'v', 3},
      {'b', 3},
      {'n', 3},
      {'m', 3}
    };
    vector<string> r;
    for(auto &i : words) {
      int line = m[tolower(i[0])];
      int flag = 0;
      for(int j = 1; j < i.size(); ++j) {
        if(m[tolower(i[j])] != line) {
          flag = 1;
          break;
        }
      }
      if(flag == 0) {
        r.push_back(i);
      }
    }
    return r;
  }
};

int main() {
  vector<string> v = {"Hello", "Alaska", "Dad", "Peace"};
  Solution s;
  vector<string> r = s.findWords(v);
  for(auto &i : r) {
    cout << i << endl;
  }
  return 0;
}