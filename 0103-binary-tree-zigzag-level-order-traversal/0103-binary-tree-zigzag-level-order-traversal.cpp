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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag;
        if(root == NULL) return zigzag;

        queue<TreeNode*> q;
        q.push(root);

        bool check = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                int idx = check ? i : (size - i - 1);
                level[idx] = node -> val;

                if(node -> left != NULL) q.push(node -> left);
                if(node -> right != NULL) q.push(node -> right);
            }
            zigzag.push_back(level);
            check = !check; //just flips the boolean each level — true becomes false, false becomes true.
        }
        return zigzag;
    }
};