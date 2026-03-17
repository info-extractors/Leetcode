class Solution {
public:

    void explore(vector<vector<char>> &board,int i,int j,vector<vector<bool>> &visited){

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == 'X' || (board[i][j] == 'O' && visited[i][j] == true)) return;
        
        visited[i][j] = true;

        explore(board,i + 1,j,visited);
        explore(board,i - 1,j,visited);
        explore(board,i,j - 1,visited);
        explore(board,i,j + 1,visited);
    }

    void solve(vector<vector<char>>& board) {
        
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));

        for(int j = 0;j < board[0].size();j++){
            if (board[0][j] == 'O'){
                explore(board,0,j,visited);
            }
            if (board[board.size() - 1][j] == 'O'){
                explore(board,board.size() - 1,j,visited);
            }
        }

        for(int i = 0;i < board.size();i++){
            
            if (board[i][0] == 'O'){
                explore(board,i,0,visited);
            }
            if (board[i][board[0].size() - 1] == 'O'){
                explore(board,i,board[0].size() - 1,visited);
            }
        }

        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                if (board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};