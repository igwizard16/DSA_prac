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
    TreeNode* buildBT(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int p_start, int p_end, map<int, int>& mpp){
        if(p_start > p_end || in_start > in_end) return NULL;

        TreeNode* root = new TreeNode(postorder[p_end]);

        int rootidx = mpp[postorder[p_end]];
        int numLeft = rootidx - in_start;

        root -> left = buildBT(inorder, in_start, rootidx - 1, postorder, p_start, p_start + numLeft - 1, mpp);

        root -> right = buildBT(inorder, rootidx + 1, in_end, postorder, p_start + numLeft, p_end - 1, mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mpp;

        for(int i = 0; i < inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        
        return buildBT(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, mpp);
    }
};