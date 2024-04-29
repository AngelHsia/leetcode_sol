#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        int perimeter = 0;

        for (int r=0 ; r<nRow ; r++) {
            for (int c=0 ; c<nCol ; c++) {
                if (grid[r][c]==1) {
                    perimeter += 4;
                    if (r>0 && grid[r-1][c]==1) {
                        perimeter -= 2;
                    }
                    if (c>0 && grid[r][c-1]==1) {
                        perimeter -= 2;
                    }
                }
            }
        }

        return perimeter;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    cout << sol.islandPerimeter(grid) << endl;
    return 0;
}
