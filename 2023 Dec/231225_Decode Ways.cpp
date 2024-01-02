#include <iostream>
#include <string>
#include <vector>
using namespace std;

// use DP (bottom-up)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n==0 || s[0]=='0') return 0;
        if (n==1) return 1;
        vector<int> dp(n,0);

        dp[0] = 1;

        if (s[1]=='0') {
            if (s[0]=='1' || s[0]=='2') {
                dp[1] = 1;
            } else {
                return 0;
            }
        } else if (s[0]=='1' || (s[0]=='2' && s[1]<'7')) {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }

        for (int i=2 ; i<n ; i++) {
            if (s[i]=='0') {
                if (s[i-1]=='1' || s[i-1]=='2') {
                    dp[i] = dp[i-2];
                    continue;
                } else {
                    return 0;
                }
            }
            if (s[i-1]=='0') {
                dp[i] = dp[i-1];
            } else if (s[i-1]=='1') {
                dp[i] = dp[i-1] + dp[i-2];
            } else if (s[i-1]=='2') {
                if (s[i]<'7') {
                    dp[i] = dp[i-1] + dp[i-2];
                } else {
                    dp[i] = dp[i-1];
                }
            } else {
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};


int main() {
    Solution solution;
    string s = "226";
    int res = solution.numDecodings(s);
    return 0;
}
