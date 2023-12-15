#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string destination = "";
        int nPath = paths.size();
        bool flag = 1;

        for (int i=0 ; i<nPath ; i++) {
            destination = paths[i][1];
            flag = 1;
            for (int j=0 ; j<nPath ; j++) {
                if (paths[j][0]==destination) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) break;
        }
        return destination;
    }
};

int main() {
    Solution solution;
    vector<vector<string>> paths {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    string destination = solution.destCity(paths);
    return 0;
}
