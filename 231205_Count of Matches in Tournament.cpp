#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        int match = 0;
        while (n>1) {
            if(n%2==0) {
                match += n/2;
                n = n/2;
            } else {
                match += (n-1)/2;
                n = (n-1)/2 + 1;
            }
        }
        return match;
    }
};

int main() {
    Solution solution;
    int n = 14;
    int res = solution.numberOfMatches(n);
    return 0;
}
