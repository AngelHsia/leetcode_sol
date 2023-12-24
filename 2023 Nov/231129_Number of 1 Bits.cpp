#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        unsigned int m = n;
        int n_one=0;
        for (int i=0 ; i<32 ; i++) {
            if (m%2==1) {
                n_one++;
            }
            m = m/2;
        }
        return n_one;
    }
};

int main(){
    Solution h_weight;
    uint32_t n = 00000000000000000000000000001011;
    return h_weight.hammingWeight(n);
}
