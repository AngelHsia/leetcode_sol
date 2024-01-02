#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookieIdx = 0;
        int nChildren = g.size();
        int nCookies = s.size();
        int res = 0;
        for (int i=0 ; i<nChildren && cookieIdx<nCookies ; i++) {
            for (int j=cookieIdx ; j<nCookies ; j++) {
                if (s[j]>= g[i]) {
                    res++;
                    cookieIdx = j+1;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> g {1,2,3};
    vector<int> s {1,1};
    int n = solution.findContentChildren(g,s);
    return 0;
}
