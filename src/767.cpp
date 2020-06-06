#include <iostream>
#include <set>
#include <utility>
#include "header.h"

class Solution {
public:
  string reorganizeString(string S) {
    string res(S);
    map<char, int> multiMap;

    for(decltype(S.size()) i = 0; i < S.size(); i++) {
      ++multiMap[S[i]];
    }

    //按字符数递减排序
    vector<pair<char, int>> vec(multiMap.begin(), multiMap.end());
    sort(vec.begin(), vec.end(), [](const pair<char, int> &lhs
                                    ,const pair<char, int> &rhs) {
      return lhs.second > rhs.second;
    });

    //不存在
    if(vec.size() > 0 && vec[0].second > (S.size() + 1)/2) {
      return "";
    }

    //确保存在的情况下先填满偶数位，再填奇数位
    int odd = 1, even = 0;
    for(int i = 0; i < vec.size(); i++) {
      while(vec[i].second > 0 && even < S.size()) {
        res[even] = vec[i].first;
        --vec[i].second;
        even += 2;
      }
      while(vec[i].second > 0 && odd < S.size()) {
        res[odd] = vec[i].first;
        --vec[i].second;
        odd += 2;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.reorganizeString("aab") << endl;
  return 0;
}