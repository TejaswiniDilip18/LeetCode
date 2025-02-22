class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(); //rows
        int cols = grid[0].size(); //cols

        int islandCount = 0;

        queue<pair<int,int>> neighbors;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for(size_t i=0; i<rows; i++){
            for(size_t j=0; j<cols; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    islandCount++;
                    neighbors.push({i,j});
                    visited[i][j] = true; // visited
                
                    while(!neighbors.empty()){
                        auto curr = neighbors.front();
                        neighbors.pop();

                        for(auto dir: dirs){
                            int r = curr.first + dir[0];
                            int c = curr.second + dir[1];

                            if(r>=0 && r<rows && c>=0 && c<cols){
                                if(grid[r][c] == '1' && !visited[r][c]){
                                    neighbors.push({r,c});
                                    visited[r][c] = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        return islandCount;
    }
};