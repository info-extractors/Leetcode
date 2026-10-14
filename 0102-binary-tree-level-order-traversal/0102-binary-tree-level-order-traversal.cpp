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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (root == nullptr) return {};

        queue<TreeNode*> q;
        vector<vector<int>> level_order;
        q.push(root);

        while(!q.empty()){

            int level_size = q.size();
            vector<int> curr_level;
            for(int i = 0;i < level_size;i++){

                TreeNode* currNode = q.front();q.pop();
                curr_level.push_back(currNode -> val);

                if (currNode -> left) q.push(currNode -> left);
                if (currNode -> right) q.push(currNode -> right);
            }

            level_order.push_back(curr_level);

        }


        return level_order;
    }
};