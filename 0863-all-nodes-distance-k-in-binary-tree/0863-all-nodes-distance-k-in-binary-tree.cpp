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
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front(); q.pop();
            if(current -> left){
                parent_track[current -> left] = current;
                q.push(current -> left);
            }
            if(current -> right){
                parent_track[current -> right] = current;
                q.push(current -> right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track; //node -> parent
        mark_parent(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        //2nd BFS to go upto k level from target node and using our hashtable info
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front(); q.pop();
                if(current -> left && !visited[current -> left]){
                    q.push(current -> left);
                    visited[current -> left] = true;
                }
                if(current -> right && !visited[current -> right]){
                    q.push(current -> right);
                    visited[current -> right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            res.push_back(curr -> val);
        }
        return res;
    }
};