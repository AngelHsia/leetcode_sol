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

#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    TreeNode* addOneRow (TreeNode* root, int val, int depth) {
        if (depth==1) {
            TreeNode* root2 = new TreeNode(val, root, nullptr);
            return root2;
        }

        Travel (root, val, depth-1);
        return root;
    }

    void addTwoNode (TreeNode* cur, int val) {
        cur->left = new TreeNode(val, cur->left, nullptr);
        cur->right = new TreeNode(val, nullptr, cur->right);
    }

    void Travel (TreeNode* cur, int val, int depth) {
        if (!cur) return;
        if (depth == 1) {
            addTwoNode (cur, val);
        }
        Travel (cur->left, val, depth-1);
        Travel (cur->right, val, depth-1);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(4, new TreeNode(2, new TreeNode(3), new TreeNode(1)), new TreeNode(6, new TreeNode(5), nullptr));
    TreeNode* root2 = sol.addOneRow(root, 1, 2);
    return 0;
}
