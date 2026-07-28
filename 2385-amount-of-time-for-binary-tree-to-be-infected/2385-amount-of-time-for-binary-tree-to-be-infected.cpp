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
    int ans = 0;

    int dfs(TreeNode* root, int start) {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left, start);
        int right = dfs(root->right, start);

        // Found the start node
        if (root->val == start) {
            ans = max(left, right);
            return -1;
        }

        // Start not present in either subtree
        if (left >= 0 && right >= 0) {
            return max(left, right) + 1;
        }

        // Start is in left subtree
        if (left < 0) {
            ans = max(ans, -left + right);
            return left - 1;
        }

        // Start is in right subtree
        ans = max(ans, -right + left);
        return right - 1;
    }

    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return ans;
    }
};