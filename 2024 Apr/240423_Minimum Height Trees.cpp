#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1) return {0};
        if (n==2) return {0,1};

        vector<vector<int>> adjacency_list(n);
        vector<int> degree(n,0); // # of neighbors
        for (auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        int remainingNodes = n;
        queue<int> leaves;
        for (int i=0 ; i<n ; i++) {
            if (degree[i]==1) leaves.push(i);
        }

        while (remainingNodes > 2) {
            int leavesCount = leaves.size();
            remainingNodes -= leavesCount;
            for (int i=0 ; i<leavesCount ; i++) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor: adjacency_list[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor]==1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        vector<int> res;
        while (!leaves.empty()) {
            res.push_back(leaves.front());
            leaves.pop();
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    vector<int> res = sol.findMinHeightTrees(4, edges);
    for (int i=0 ; i<res.size() ; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
