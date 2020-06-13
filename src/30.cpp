#include <iostream>
#include "header.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty()) {
            return {};
        }
        map<string, int> m;
        vector<int> res;
        int wordLength = words[0].size();
        int allLength = wordLength * words.size();
        for (int i = 0; i < words.size(); ++i) {
            ++m[words[i]];
        }

        for (int i = 0; i < wordLength; ++i) {
            map<string, int> tmpM;
            int count = 0;
            int left = i;
            for (int j = i; j < s.size(); j += wordLength) {
                string w = s.substr(j, wordLength);
                ++tmpM[w];
                ++count;
                while (tmpM[w] > m[w]) {
                    string leftStr = s.substr(left, wordLength);
                    --tmpM[leftStr];
                    left += wordLength;
                    --count;
                }

                if (count == words.size()) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};

int main() {
    string str = "wordgoodgoodgoodbestwordword";
    vector<string> v = {"word","good","best","word"};
    Solution s;
    vector<int> intV = s.findSubstring(str, v);
    for (auto &i : intV) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}