#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        int len = corridor.length();
        int n_S = 0;
        int seat = 0;
        long long ans=1;
        for (int i=0 ; i<len ; i++) {
            if (corridor[i]=='S') {
                n_S++;
            }
        }

        // no solution -> return 0
        if(n_S%2 != 0 || n_S==0) { 
            ans = 0;
            return ans;  
        }

        int k=1;  // number of ways to divide in one area
        for (int i=0 ; i<len ; i++) {
            if ((seat==0 || seat==1) && corridor[i]=='S') {
                seat += 1;
            }
            else if (seat==2 && corridor[i]=='P') {
                k += 1;
            }
            else if (seat==2 && (corridor[i]=='S' || i==len-1)) {
                ans = (ans*k) % 1000000007;
                k=1;
                seat=1;
            }
        }
        return ans % 1000000007;
    }
};

int main(){
    Solution corridor;
    string s = "SSPPSPS";
    return corridor.numberOfWays(s);
}
