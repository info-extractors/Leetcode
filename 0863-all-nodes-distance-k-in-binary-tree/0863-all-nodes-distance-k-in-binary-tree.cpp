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
    void dfs(TreeNode* root,vector<vector<int>> &graph){

        if (!root) return;

        //now take the children
        if (root -> left){

            int u = root -> val;
            int v = root -> left -> val;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (root -> right){

            int u = root -> val;
            int v = root -> right -> val;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(root -> left,graph);
        dfs(root -> right,graph);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        //need a graph representation 
        vector<vector<int>> graph(501);
        dfs(root,graph);

        vector<int> distKNodes;

        queue<pair<int,int>> q;
        vector<int> vis(501,false);

        q.push({target -> val,0});
        while(!q.empty()){

            auto [node,dist] = q.front();q.pop();
            vis[node] = true;
            if (dist == k) distKNodes.push_back(node);

            //include its neighbors;
            for(int neighbors : graph[node]){
                if (!vis[neighbors]){
                    q.push({neighbors,dist + 1});
                }
            }
        }

        return distKNodes;
    }
};