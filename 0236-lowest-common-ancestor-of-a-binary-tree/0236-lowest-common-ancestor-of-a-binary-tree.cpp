/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;

    bool findPath(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
        if (root == NULL) return false;

        path.push_back(root);

        if (root == target) return true;

        if (findPath(root->left, target, path) || findPath(root->right, target, path)) return true;

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        findPath(root, p, pathP);
        findPath(root, q, pathQ);
        TreeNode* ans = NULL;

        int n = min(pathP.size(), pathQ.size());
        for (int i = 0; i < n; i++) {
            if (pathP[i] == pathQ[i]) ans = pathP[i];
            else break;
        }
        return ans;
    }
};