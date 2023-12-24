#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1, max2, min1, min2;
        int len = nums.size();
        // First Bubble Sort
        for (int i=0 ; i<2 ; i++) {
            for (int j=0 ; j<len-1 ; j++) {
                if (nums[j]>nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        max1 = nums[len-1];
        max2 = nums[len-2];

        // Second Bubble Sort
        for (int i=0 ; i<2 ; i++) {
            for (int j=0 ; j<len-1 ; j++) {
                if (nums[j]<nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
        min1 = nums[len-1];
        min2 = nums[len-2];
        
        return (max1*max2-min1*min2);
    }
};

int main() {
    Solution solution;
    vector<int> nums{5,6,2,7,4};
    int res = solution.maxProductDifference(nums);
    return 0;
}
