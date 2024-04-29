#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> k(n,0);
        vector<vector<int>> sum(n, k);
        for (int i=0 ; i<n ; i++) {
            sum[0][i] = grid[0][i];
        }
        
        for (int i=1 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                sum[i][j] = FindMin(j, sum[i-1]) + grid[i][j];
            }
        }
        
        int min = FindMin(0, sum[n-1]);
        return min < sum[n-1][0] ? min : sum[n-1][0];
    }
    int FindMin (int col, vector<int> sum) {
        int min=30000;
        for (int c=0 ; c<col ; c++) {
            if (sum[c] < min) min = sum[c];
        }
        for (int c=col+1 ; c<sum.size() ; c++) {
            if (sum[c] < min) min = sum[c];
        }
        return min;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
    cout << sol.minFallingPathSum(grid) << endl;
    return 0;
}
