#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int n_get_pile = n/3;
        int ans = 0;

        sort(piles.begin(), piles.end(), greater<>());
        
        for (int i=0 ; i<n_get_pile ; i++) {
            ans = ans + (piles[2*i+1]);
        }
        return ans;
    }
};

int main(){
    return 0;
}