#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
    int x0, y0, x1, y1;
      if(start1[0] < end1[0]) {
        x0 = start1[0];
        y0 = start1[1];
      } else {
        x0 = end1[0];
        y0 = end1[1];
      }

      if(start2[0] < end2[0]) {
        x1 = start2[0];
        y1 = start2[1];
      } else {
        x1 = end2[0];
        y1 = end2[1];
      }

    double k1;
    int f = 0;
    if(end1[0] == start1[0]) {
      f = 1;
    } else {
      k1 = ((double)end1[1] - start1[1])/(end1[0] - start1[0]);
    }
    double b1 = start1[1] - k1*start1[0];
    double k2;
    if(end2[0] == start2[0]) {
      if(f == 1) {
        f = 3;
      } else {
        f = 2;
      }
    } else {
      k2 = ((double)end2[1] - start2[1])/(end2[0] - start2[0]);
    }
    double b2 = start2[1] - k2*start2[0];
    if(f == 1) {
      if((x0 >= start2[0] && x0 <= end2[0]) || (x0 <= start2[0] && x0 >= end2[0])) {
        return vector<double>{(double)x0, k2 * x0 + b2};
      } else {
        return vector<double>();
      }
    } else if(f == 2) {
      if((x1 >= start1[0] && x1 <= end1[0]) || (x1 <= start1[0] && x1 >= end1[0])) {
        return vector<double>{(double)x1, k1 * x1 + b1};
      } else {
        return vector<double>();
      }
    } else if(f == 3) {
      if(x0 == x1) {
        if(max(start1[1], end1[1]) == min(start2[1], end2[1])) {
          return vector<double>{(double)x0, (double)max(start1[1], end1[1])};
        }

        if(max(start2[1], end2[1]) == min(start1[1], end1[1])) {

          return vector<double>{(double)x0, (double)max(start2[1], end2[1])};
        }

        if(max(start1[1], end1[1]) < min(start2[1], end2[1])) {
          return vector<double>();
        }
        if(max(start2[1], end2[1]) < min(start1[1], end1[1])) {
          return vector<double>();
        }

        if(y0 < y1) {
          return vector<double>{(double)x1, (double)y1};
        } else {
          return vector<double>{(double)x0, (double)y0};
        }
      } else {
        return vector<double>();
      }
    }

    if(fabs(k1 - k2) < 0.000001 && fabs(b1 - b2) < 0.000001) {
      if(max(start1[1], end1[1]) < min(start2[1], end2[1])) {
        return vector<double>();
      }
      if(max(start2[1], end2[1]) < min(start1[1], end1[1])) {
        return vector<double>();
      }
      if(x0 < x1) {
        return vector<double>{(double)x1, (double)y1};
      }
      return vector<double>{(double)x0, (double)y0};
    }

    if(fabs(k1 - k2) < 0.000001) {
      return vector<double>();
    }

    double x00 = (b1 - b2)/(k2 - k1);
    double y00 = x00 * k1 + b1;
    if(x00 >= min(start1[0], end1[0]) && x00 <= max(start1[0], end1[0]) && x00 >= min(start2[0], end2[0]) && x00 <= max(start2[0], end2[0])) {
      return vector<double>{x00, y00};
    }
    return vector<double>();
  }
};

int main() {
  Solution s;
  vector<int> x1{-25, 67};
  vector<int> y1{-67, 24};
  vector<int> x2{-52, 48};
  vector<int> y2{-45, 43};
  vector<double> r = s.intersection(x1, y1, x2, y2);
  cout << r[0] << ", " << r[1] << endl;
  return 0;
}