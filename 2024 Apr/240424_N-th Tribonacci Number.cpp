#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        int a=0;
        int b=1;
        int c=1;
        if (n==0) return a;
        if (n==1) return b;
        if (n==2) return c;

        int flag = 1;
        for (int i=0 ; i<n-2 ; i++) {
            if (flag==1) {
                a = a+b+c;
                flag++;
            } else if (flag==2) {
                b = a+b+c;
                flag++;
            } else {
                c = a+b+c;
                flag = 1;
            }
        }
        return (max(a, max(b,c)));
    }
};

int main() {
    Solution sol;
    cout << sol.tribonacci(25) << endl;
    return 0;
}
