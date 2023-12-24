#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int alter1=0; // n_alternation if we want to change s to "010101..."
        int alter2=0; // n_alternation if we want to change s to "101010..."
        for (int i=0 ; i<n ; i++) {
            if(i%2==0) {
                s[i]=='0' ? alter2++ : alter1++;
            } else {
                s[i]=='0' ? alter1++ : alter2++;
            }
        }
        return min(alter1, alter2);
    }
};

int main() {
    Solution solution;
    string s = "1111";
    int res = solution.minOperations(s);
    return 0;
}
