#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> onesRow(m,0);
        vector<int> onesCol(n,0);
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                if (grid[i][j]==1) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }

        vector<vector<int>> diff(m, vector<int>(n,0));
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                diff[i][j] = 2*onesRow[i] + 2*onesCol[j] - m - n;
            }
        }
        return diff;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid {{0,1,1},{1,0,1},{0,0,1}};
    vector<vector<int>> diff = solution.onesMinusZeros(grid);
    return 0;
}
