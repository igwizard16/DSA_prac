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
    void mark_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr -> left){
                q.push(curr -> left);
                parent_track[curr -> left] = curr;
            }
            if(curr -> right){
                q.push(curr -> right);
                parent_track[curr -> right] = curr;
            }
        }
    } 

    int amountOfTime(TreeNode* root, int start) {
        if(root == NULL) return 0;
        unordered_map<TreeNode*, TreeNode*> parent_track;
        mark_parent(root, parent_track);
        
        //finding the start and converting into node
        TreeNode* start_node = NULL;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr -> val == start){
                start_node = curr;
                break;
            }
            if(curr -> left){
                q.push(curr -> left);
            }
            if(curr -> right){
                q.push(curr -> right);
            }
        }

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode* > bfs;

        bfs.push(start_node);
        visited[start_node] = true; 
        int minutes = 0;

        while(!bfs.empty()){
            int size = bfs.size();
            bool infected = false;

            for(int i = 0; i < size; i++){
                TreeNode* curr = bfs.front(); bfs.pop();
                if(curr -> left && !visited[curr -> left]){
                    bfs.push(curr -> left);
                    visited[curr -> left] = true;
                    infected = true;
                }
                if(curr -> right && !visited[curr -> right]){
                    bfs.push(curr -> right);
                    visited[curr -> right] = true;
                    infected = true;
                }
                if(parent_track.count(curr) && !visited[parent_track[curr]]){
                    bfs.push(parent_track[curr]);
                    visited[parent_track[curr]] = true;
                    infected = true;
                }
            }
            if(infected) minutes++;
        }

        return minutes;
    }
};