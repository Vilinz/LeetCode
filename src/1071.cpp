#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool valid(string T, string s) {
        string result{""};
        int count = s.size() / T.size();
        for(int i = 0; i < count; i++) {
            result += T;
        }
        return (result == s);
    }
    string gcdOfStrings(string str1, string str2) {
        int str1Len = str1.size(), str2Len = str2.size();
        for(int i = min(str1Len, str2Len); i > 0; i--) {
            string temp = str1.substr(0, i);
            if(valid(temp, str1) && valid(temp, str2)) {
                return temp;
            }
        }
        return "";
    }
};

int main() {
    string str1{"ABABAB"}, str2{"ABAB"};
    Solution s;
    cout << s.gcdOfStrings(str1, str2) << endl;
    return 0;
}