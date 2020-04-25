#include <iostream>
#include "header.h"

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    for(int i = 1; i < prices.size(); i++) {
      if(prices[i] > prices[i - 1]) {
        profit += (prices[i] - prices[i - 1]);
      }
    }
    return profit;
  }
};

int main() {
  vector<int> v{7,6,4,3,1};
  Solution s;
  cout << s.maxProfit(v) << endl;
  return 0;
}