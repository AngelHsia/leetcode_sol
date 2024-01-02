#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        char cur_color = colors[0];
        int cStart, cEnd;
        bool find = 0; // 0: good, 1: find consecutive color
        int totalTime = 0;
        for (int i=1 ; i<n ; i++) {
            if (colors[i]==cur_color) {
                // find consecutive color
                if (find==0) {
                    find = 1;
                    cStart = i-1;
                }
            } else {
                if (find==1) {
                    cEnd = i-1;
                    totalTime += GetTimeNeeded(neededTime, cStart, cEnd);
                    find = 0;
                }
                cur_color = colors[i];
            }
        }
        if (find == 1) {
            totalTime += GetTimeNeeded(neededTime, cStart, n-1);
        }
        return totalTime;
    }
private: 
    int GetTimeNeeded(vector<int>& neededTime, int start, int end) {
        int time=0;
        int maxTime=0;
        for (int i=start ; i<end+1 ; i++) {
            time += neededTime[i];
            maxTime = max(maxTime, neededTime[i]);
        }
        time -= maxTime;
        return time;
    }
};


int main() {
    Solution solution;
    string colors = "bbbaaa";
    vector<int> neededTime = {4,9,3,8,8,9};
    int res = solution.minCost(colors, neededTime);
    return 0;
}
