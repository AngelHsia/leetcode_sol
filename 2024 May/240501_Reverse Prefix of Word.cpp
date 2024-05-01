#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        int len = word.length();
        string a = "";
        for ( ; i<len ; i++) {
            a += word[i];
            if (word[i]==ch) break;
        }

        if (i==len) return word;
        
        // reverse 0~i segment
        reverse(a.begin(), a.end());
        for (int j=i+1 ; j<len ; j++) {
            a += word[j];
        }
        return a;
    }
};

int main() {
    Solution sol;
    string word = "abcdef";
    char ch = 'd';
    cout << sol.reversePrefix(word, ch) << endl;
    return 0;
}
