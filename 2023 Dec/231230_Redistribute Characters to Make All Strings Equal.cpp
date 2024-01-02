#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int len = words.size();
        if (len==1) {
            return true;
        }
        vector<int> count(26,0);
        for (int i=0 ; i<len ; i++) {
            int n = words[i].length();
            for (int j=0 ; j<n ; j++) {
                count[ words[i][j]-'a' ]++;
            }
        }
        for (int i=0 ; i<26 ; i++) {
            if ( count[i]%len != 0 ) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution solution;
    vector<string> words = {"abc","aabc","bc"};
    bool res = solution.makeEqual(words);
    return 0;
}
