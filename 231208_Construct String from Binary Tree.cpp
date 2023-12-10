#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Definition for a binary tree node.
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
    string res = "";
    string tree2str(TreeNode* root) {
        helper(root);
        return res;
    }
    void helper(TreeNode* root) {
        if (root != nullptr) {
            res.append(to_string(root->val));
            if (root->left != nullptr && root->right == nullptr) {
                res.append("(");
                helper(root->left);
                res.append(")");
            }
            else if (root->right != nullptr) {
                res.append("(");
                helper(root->left);
                res.append(")");
                res.append("(");
                helper(root->right);
                res.append(")");
            }
        }
    }
};

int main() {
    return 0;
}
