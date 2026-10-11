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
    void inorder(TreeNode* root, vector<int>& recover){
        if(root == NULL) return;
        inorder(root -> left, recover);
        recover.push_back(root -> val);
        inorder(root -> right, recover);
    }
    
    void replace(TreeNode* root, vector<int>& recover, int& idx){
        if(root == NULL) return;
        replace(root -> left, recover, idx);
        root -> val = recover[idx++];
        replace(root -> right, recover, idx);
    }

    void recoverTree(TreeNode* root) {
        vector<int> recover;
        inorder(root, recover);
        
        sort(recover.begin(), recover.end());

        int idx = 0;
        replace(root, recover, idx);
    }
};