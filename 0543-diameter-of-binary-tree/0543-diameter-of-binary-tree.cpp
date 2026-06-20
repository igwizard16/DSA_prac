/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root){
        if(root == NULL) return 0;

        int lheight = height(root -> left);
        int rheight = height(root -> right);

        diameter = max(diameter, lheight + rheight);

        return 1 + max(lheight, rheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};