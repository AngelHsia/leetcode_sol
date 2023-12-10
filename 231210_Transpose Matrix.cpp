#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> t(n, vector<int>(m));
        for (int i=0 ; i<m ; i++) {
            for (int j=0 ; j<n ; j++) {
                t[j][i] = matrix[i][j];
            }
        }
        return t;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> t_matrix = solution.transpose(matrix);
    return 0;
}
