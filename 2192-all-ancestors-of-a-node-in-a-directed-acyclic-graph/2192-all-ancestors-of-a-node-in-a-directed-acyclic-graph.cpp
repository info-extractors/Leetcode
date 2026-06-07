class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int> inDegree(n);
        vector<vector<int>> graph(n);

        for(vector<int> edge : edges){

            int u = edge[0];
            int v = edge[1];

            inDegree[v]++;
            graph[u].push_back(v);
        }

        queue<int> q;

        for(int i = 0;i < inDegree.size();i++){
            if (inDegree[i] == 0) q.push(i);
        }

        vector<set<int>> temp_ans(n);

        while(!q.empty()){

            int frontNode = q.front();q.pop();

            for(int neighbor : graph[frontNode]){

                temp_ans[neighbor].insert(frontNode);

                temp_ans[neighbor].insert(
    temp_ans[frontNode].begin(),
    temp_ans[frontNode].end()
);

                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) q.push(neighbor);
            }
        }

        vector<vector<int>> ans(n);

        for(size_t i{};i < n;i++){
            ans[i] = vector<int>(temp_ans[i].begin(),temp_ans[i].end());
        }

        return ans;
    }
};

// even if the indegree is not zero the node is still the ancestor of the node 
//so we have to do it