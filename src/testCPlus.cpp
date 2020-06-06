#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <functional>
using namespace std;

class PrintString {
public:
  PrintString(ostream &o = cout, string s = "hello") : os(o), str(s) {

  }
  void operator() (const string &s) const {
    os << s << str << endl;
  }
private:
  ostream &os;
  string str;
};

int main() {
  PrintString print;
  string s = "0";
  print(s);
  return 0;
}