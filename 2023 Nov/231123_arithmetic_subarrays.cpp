#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(len, 0);

        int sum = 0;
        for (int i=0 ; i<len ; i++){
            sum += nums[i];
        }
        int left_sum = 0;
        int right_sum = sum;

        for (int i=0 ; i<len ; i++) {
            result[i] = right_sum - (len-i)*nums[i] -left_sum + (i)*nums[i];
            right_sum -= nums[i];
            left_sum += nums[i];
        }
        return result;
    }
};

int main(){
    return 0;
}
