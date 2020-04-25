#include <iostream>
using namespace std;

int main() {
  int a = 9;
  void *pv = &a;
  cout << *(int*)pv << endl;
  return 0;
}