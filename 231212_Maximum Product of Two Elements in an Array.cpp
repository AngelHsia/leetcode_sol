#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int max1=1, max2=1;
        for (int i=0 ; i<len ; i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] > max2) {
                max2 = nums[i];
            }
        }
        return (max1-1) * (max2-1);
    }
};

int main() {
    Solution solution;
    vector<int> arr {3,4,5,2};
    int integer = solution.maxProduct(arr);
    return 0;
}
