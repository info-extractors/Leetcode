class Solution {
public:

    void dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>> &visited){

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || (grid[i][j] == 1 && visited[i][j] == true)) return;

        visited[i][j] = true;

        dfs(grid,i + 1,j,visited);
        dfs(grid,i - 1,j,visited);
        dfs(grid,i,j - 1,visited);
        dfs(grid,i,j + 1,visited);

        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));

        for(int col = 0;col < grid[0].size();col++){

            if (grid[0][col] == 1){
                dfs(grid,0,col,visited);
            }

            if (grid[grid.size() - 1][col] == 1){
                dfs(grid,grid.size() - 1,col,visited);
            }
        }

        for(int row = 0;row < grid.size();row++){

            if (grid[row][0] == 1){
                dfs(grid,row,0,visited);
            }

            if (grid[row][grid[0].size() - 1] == 1){
                dfs(grid,row,grid[0].size() - 1,visited);
            }
        }

        int count = 0;

        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if (grid[i][j] == 1 && visited[i][j] == false){
                    count++;
                }
            }
        }

        return count;
    }
};