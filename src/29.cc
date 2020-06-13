#include <iostream>
#include "header.h"

class Solution {
public:
  int div(long a, long b) {
    if(a < b) {
      return 0;
    }
    long count = 1;
    long tmpb = b;
    while(tmpb + tmpb < a) {
      count += count;
      tmpb += tmpb;
    }
    return count + div(a - tmpb, b);
  }
  int divide(int dividend, int divisor) {
    if(dividend == 0) return 0;
    if(divisor == 1) return dividend;
    if(divisor == -1){
        if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
        return INT_MAX;// 是最小的那个，那就返回最大的整数啦
    }
    int flag = 0;
    if(dividend > 0 && divisor > 0 || (dividend < 0 && divisor < 0)) {
      flag = 1;
    }
    long tmpDividend = dividend;
    long tmpDivisor = divisor;
    tmpDividend = tmpDividend < 0 ? -tmpDividend : tmpDividend;
    tmpDivisor = tmpDivisor < 0 ? -tmpDivisor : tmpDivisor;
    int res = div(tmpDividend, tmpDivisor);
    if(flag == 0) {
      return -res;
    } else {
      return res > INT_MAX ? INT_MAX : res;
    }
  }
};

int main() {
  Solution s;
  cout << s.divide(7, -3) << endl;
  return 0;
}