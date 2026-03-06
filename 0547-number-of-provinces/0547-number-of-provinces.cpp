class Solution {
public:

    void dfs(vector<vector<int>> &isConnected,int start,vector<bool> &visited){

        visited[start] = true;

        for(int j = 0;j < isConnected[0].size();j++){

            if (isConnected[start][j] == 1 && visited[j] != true){
                dfs(isConnected,j,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<bool> visited(isConnected.size(),false);

        int count = 0;
        for(int i = 0;i < isConnected.size();i++){

            if (!visited[i]){
                dfs(isConnected,i,visited);
                count++;
            }
        }

        return count;
    }
};