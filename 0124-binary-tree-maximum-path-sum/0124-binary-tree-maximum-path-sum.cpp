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
    int path_sum(TreeNode* root, int& maxPath){
        if(root == NULL) return 0;

        int lpath = max(0, path_sum(root -> left, maxPath));
        int rpath = max(0, path_sum(root -> right, maxPath));

        maxPath = max(maxPath, lpath + rpath + root -> val);
        return max(lpath, rpath) + root -> val;
    }
    
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        path_sum(root, maxPath);
        return maxPath;
    }
};