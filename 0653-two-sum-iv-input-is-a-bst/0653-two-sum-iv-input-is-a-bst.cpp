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
    void store(TreeNode* root, unordered_map<int, int>& mpp){
        if(root == NULL) return;

        mpp[root -> val]++;
        store(root -> left, mpp);
        store(root -> right, mpp);
    }

    bool find(TreeNode* root, unordered_map<int, int>& mpp, int key){
        if(root == NULL) return false;
        int target = key - root -> val;

        if(mpp.find(target) != mpp.end()){
            if(target != root -> val)
                return true;
            if(mpp[target] >= 2) return true;
        }

        
        if(find(root -> left, mpp, key)) return true;
        if(find(root -> right, mpp, key)) return true;

        return false;
    }

    bool findTarget(TreeNode* root, int k) {

        unordered_map<int, int> mpp;

        store(root, mpp);
        
        return find(root, mpp, k);
    }
};