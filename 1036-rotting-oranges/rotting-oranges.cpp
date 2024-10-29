class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int freshOranges = 0;

        std::queue<std::pair<int,int>> rottenOranges;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==2){
                    rottenOranges.push({i,j});
                }
                else if(grid[i][j]==1) freshOranges++;
            }
        }

        if(freshOranges==0) return 0;

        int minutes=-1;
        vector<std::pair<int,int>> directions = {{-1,0}, {0,-1}, {0, 1}, {1, 0}};

        while(!rottenOranges.empty()){
            int level = rottenOranges.size();

            for(int i=0; i<level; i++){
                auto [row, col] = rottenOranges.front();
                rottenOranges.pop();

                for(auto [i, j] : directions){
                    int newRow = i + row;
                    int newCol = j + col;

                    if(newRow>=0 && newRow < rows && newCol>=0 && newCol< cols && grid[newRow][newCol]==1){
                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        rottenOranges.push({newRow,newCol});
                    }
                }
            }
            minutes++;
        }

        return freshOranges==0 ? minutes : -1;
    }
};