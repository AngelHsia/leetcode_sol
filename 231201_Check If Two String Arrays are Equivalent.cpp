#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        string str1="", str2="";
        for (int i=0 ; i<len1 ; i++) {
            str1 += word1[i];
        }
        for (int i=0 ; i<len2 ; i++) {
            str2 += word2[i];
        }
        return (str1==str2);
    }
};

int main(){
    Solution solution;
    vector<string> word1{"ab", "c"};
    vector<string> word2{"a", "bc"};
    return solution.arrayStringsAreEqual(word1, word2);
}
