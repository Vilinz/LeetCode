#include <iostream>
#include "header.h"

class Solution {
public:
/*
  vector<string> readBinaryWatch(int num) {
    vector<string> res;
    for(int i = 0; i < 12; i++) {
      for(int j = 0; j < 60; j++) {
        if(countOne(i) + countOne(j) == num) {
          if(j < 10) {
            res.push_back(to_string(i) + ":" + '0' + to_string(j));
          } else {
            res.push_back(to_string(i) + ":" + to_string(j));
          }
        }
      }
    }
    return res;
  }

  int countOne(int n) {
    int count = 0;
    while(n) {
      if(n & 1) {
        count++;
      }
      n >>= 1;
    }
    return count;
  }
*/
  vector<string> readBinaryWatch(int num) {
    vector<string> res;
    if(num == 0) {
      return {"0:00"};
    }
    vector<int> p;
    int pos = 0;
    backtrace(res, num, pos, p);
    return res;
  }

  void backtrace(vector<string> &res, int num, int pos, vector<int> &p) {
    if(num == 0) {
      string str = getTime(p);
      if(str != "nullptr") {
        res.push_back(str);
      }
      return;
    }

    for(int i = pos; i < 10; i++) {
      p.push_back(i);
      backtrace(res, num - 1, i + 1, p);
      p.pop_back();
    }
  }

  string getTime(vector<int> &p) {
    int h = 0, m = 0;
    for(int i = 0; i < p.size(); i++) {
      if(p[i] < 4) {
        h += 1 << p[i];
      } else {
        m += 1 << (p[i] - 4);
      }
    }
    if(h > 11 || m > 59) {
      return "nullptr";
    }

    string str;
    str += to_string(h);
    str += ":";
    if(m < 10) {
      str += "0";
    }
    str += to_string(m);
    return str;
  }
};

int main() {
  Solution s;
  vector<string> r = s.readBinaryWatch(1);
  for(auto i : r) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}