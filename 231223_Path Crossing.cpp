#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.length();
        int x=0;
        int y=0;
        for (int j=0 ; j<n ; j++) {
            x=0;
            y=0;
            for (int i=j ; i<n ; i++){
                if (path[i]=='N') {
                    y ++;
                } else if (path[i]=='S') {
                    y --;
                } else if (path[i]=='E') {
                    x ++;
                } else {
                    x --;
                }
                if (x==0 && y==0) return 1;            
            }
        }
        return 0;
    }
};

int main() {
    Solution solution;
    string path = "NESWW";
    bool res = solution.isPathCrossing(path);
    return 0;
}
