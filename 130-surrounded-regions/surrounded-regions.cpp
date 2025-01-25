class Solution {
private:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int r, int c, vector<vector<int>>& dirs, int& rows, int& cols){
        visited[r][c] = 1;

        for(auto& dir: dirs){
            int newRow = r + dir[0];
            int newCol = c + dir[1];

            if(newRow >= 0 && newRow<rows && newCol >= 0 && newCol<cols && !visited[newRow][newCol] && board[newRow][newCol]=='O'){
                dfs(board, visited, newRow, newCol, dirs, rows, cols);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols,0));

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // check first and last row for presence of 'O'
        for(size_t j=0; j<cols; j++){
            if(!visited[0][j] && board[0][j]=='O'){
                dfs(board, visited, 0, j, dirs, rows, cols);
            }

            if(!visited[rows-1][j] && board[rows-1][j]=='O'){
                dfs(board, visited, rows-1, j, dirs, rows, cols);
            }
        }

        // check first and last column for presence of 'O'
        for(size_t i=0; i<rows; i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(board, visited, i, 0, dirs, rows, cols);
            }

            if(!visited[i][cols-1] && board[i][cols-1]=='O'){
                dfs(board, visited, i, cols-1, dirs, rows, cols);
            }
        }

        for(size_t i=0; i<rows; i++){
            for(size_t j=0; j<cols; j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

    }
};