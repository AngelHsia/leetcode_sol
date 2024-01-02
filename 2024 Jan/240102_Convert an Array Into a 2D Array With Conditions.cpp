#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int len = nums.size();

        // sort the "nums" array in ascending order
        sort(nums.begin(), nums.end());

        vector<vector<int>> M;
        M.push_back( {nums[0]} );
        int currentNum, previousNum = nums[0];
        int idx=1;  // 指向要插入的 row index

        for (int i=1 ; i<len ; i++) {
            currentNum = nums[i];
            if (currentNum==previousNum) {
                // recurrent number
                // to create a new row or to add to a existed row, that's the question.
                M.size()<=idx ? 
                    M.push_back( {currentNum} ) : M[idx].push_back(currentNum);
                idx++;
            } else {
                // new number
                previousNum = currentNum;
                M[0].push_back( currentNum );
                idx=1;
            }
        }
        return M;
    }
};

int main() {
    Solution solution;
    vector<int> nums {1,3,4,1,2,3,1};
    vector<vector<int>> M = solution.findMatrix(nums);
    return 0;
}
