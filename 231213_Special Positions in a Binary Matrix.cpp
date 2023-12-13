#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int specials = 0;
        for (int i=0 ; i<m ; i++) {
            int col = CheckRow(i, mat);
            if (col != -1) {
                if (CheckCol(col, mat)) {
                    specials++;
                }
            }
        }
        return specials;
    }
private:
    // Check if there's only one 1 in this row. If yes, return the index. If no, return -1.
    int CheckRow(int row, vector<vector<int>>& mat) {  
        int n = mat[0].size();
        int index = -1;
        for (int col=0 ; col<n ; col++) {
            if (mat[row][col]==1) {
                if (index==-1) {
                    index = col;
                } else {
                    return -1;
                }
            }
        }
        return index;
    }
    bool CheckCol(int col, vector<vector<int>>& mat) {
        int m = mat.size();
        bool flag = 0;
        for (int row=0 ; row<m ; row++) {
            if (mat[row][col]==1) {
                if (flag==0) {
                    flag = 1;
                } else {
                    return 0;
                }
            }
        }
        return flag;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> mat {{1,0,0},{0,0,1},{1,0,0}};
    int specials = solution.numSpecial(mat);
    return 0;
}
