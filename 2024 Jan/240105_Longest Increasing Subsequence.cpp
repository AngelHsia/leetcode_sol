#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        vector<int> dp(len,1);
        for (int i=1 ; i<len ; i++) {
            for (int j=0 ; j<i ; j++) {
                if (nums[i]>nums[j]) {
                    dp[i] = max( dp[i] , dp[j]+1 );
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums {0,1,0,3,2,3};
    int res = solution.lengthOfLIS(nums);
    return 0;
}
