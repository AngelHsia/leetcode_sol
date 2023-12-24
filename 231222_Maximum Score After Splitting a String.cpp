#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int maxScore(string s) {
        int len = s.length();
        int score=0;
        int max_score=0;

        // suppose split between s[0] & s[1]
        if (s[0]=='0') score=1;
        else score=0;
        for(int i=1 ; i<len ; i++) {
            if (s[i]=='1') {
                score++;
            }
        }
        max_score = score;

        // suppose split between s[i-1] & s[i]
        for (int i=2 ; i<len ; i++) {
            if (s[i-1]=='0') {
                score++;
            } else {
                score--;
            }
            max_score = max(max_score, score);
        }
        return max_score;
    }
};

int main() {
    Solution solution;
    string s = "011101";
    int res = solution.maxScore(s);
    return 0;
}
