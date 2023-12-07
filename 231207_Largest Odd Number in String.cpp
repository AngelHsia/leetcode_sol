#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int len = num.length();
        string res = "";
        for (int i=len-1 ; i>=0 ; i--) {
            int n = int(num[i]-'0');
            if(n%2==1) {
                res = num.substr(0,i+1);
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string num = "35427";
    string res = solution.largestOddNumber(num);
    return 0;
}
