#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int w = n/7;
        int r = n-(w*7);
        int res = w*(7*w+49)/2;
        int s = 1+w;
        for (int i=0 ; i<r ; i++) {
            res += s;
            s++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    int n = 20;
    int res = solution.totalMoney(n);
    return 0;
}
