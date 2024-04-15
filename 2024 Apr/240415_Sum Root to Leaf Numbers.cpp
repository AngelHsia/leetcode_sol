#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        long long res = 0;
        vector<int> path;
        Travel (root, res, path);
        return res;
    }

    void Travel (TreeNode* root, long long& res, vector<int>& path) {
        path.push_back(int(root->val));
        if (root->left) {
            Travel (root->left , res, path);
            path.pop_back();
        }
        if (root->right) {
            Travel (root->right, res, path);
            path.pop_back();
        }
        if (!root->left && !root->right) {
            // encounter leaf!
            int len = path.size();
            for (int i=0 ; i<len ; i++) {
                res += path[i]*pow(10, len-i-1);
            }
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    Solution sol;
    cout << sol.sumNumbers(root) << endl;
    return 0;
}
