#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int len = s.length();
        
        vector<int> Chars(26,0);
        for (int i=0 ; i<len ; i++) {
            Chars[ s[i]-'a' ]++;
            Chars[ t[i]-'a' ]--;
        }
        for (int i=0 ; i<26 ; i++) {
            if (Chars[i]!=0) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string s = "anagram", t = "nagaram";
    bool res = solution.isAnagram(s, t);
    return 0;
}
