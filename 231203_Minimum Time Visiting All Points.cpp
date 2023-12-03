#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(); // number of points
        int time = 0;
        for (int i=0 ; i<n-1 ; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[i+1][0], y2 = points[i+1][1];
            int dx = abs(x1-x2), dy = abs(y1-y2);
            time += max(dx, dy);
        }
        return time;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points{{1,1},{3,4},{-1,0}};
    return solution.minTimeToVisitAllPoints(points);
}
