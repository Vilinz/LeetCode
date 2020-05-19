#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <functional>
using namespace std;

int main() {
  int a = 1, b = 3;
  auto pa = make_pair(std::move(a), b);
  cout << pa.first << ", " << pa.second << endl;
  a = 2;
  b = 4;
  cout << pa.first << ", " << pa.second << endl;
  return 0;
}