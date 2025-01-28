class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0)); //initialize visited array

        queue<pair<int,int>> q;

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // find 1's in 1st and last row & col
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(i==0 | i == rows-1 | j==0 | j == cols-1){
                    if(grid[i][j] == 1 && !visited[i][j]){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }

        if(q.empty()) return 0;

        while(!q.empty()){
            auto land = q.front();
            q.pop();

            for(auto& dir: dirs){
                int i = land.first + dir[0];
                int j = land.second + dir[1];

                if(i>=0 && i<rows && j>=0 && j<cols && !visited[i][j] && grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }

        int landCount = 0;

        for(size_t i=0; i<rows; i++){
            for(size_t j=0; j<cols; j++){
                if(!visited[i][j] && grid[i][j]==1){
                    landCount++;
                    visited[i][j]=1;
                }
            }
        }

        return landCount;
    }
};