#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> maxDepthAfterSplit(string seq) {
    int dep = 0;
    vector<int> result;
    for(auto c : seq) {
      if(c == '(') {
        dep++;
        result.push_back(dep % 2);
      } else {
        result.push_back(dep % 2);
        dep--;
      }
    }
    return result;
  }
};

int main() {
  string s("(()())");
  Solution so;
  vector<int> r = so.maxDepthAfterSplit(s);
  for(auto i : r) {
    cout << i << endl;
  }
  return 0;
}