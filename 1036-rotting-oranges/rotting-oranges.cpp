class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int time = -1;
        int freshOranges = 0;

        queue<pair<int, int>> rottenOranges;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==2){
                    rottenOranges.push({i,j});
                }
                else if(grid[i][j]==1)
                    freshOranges++;
            }
        }

        if(freshOranges==0) return 0;

        vector<vector<int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // {up, down, left, right}

        while(!rottenOranges.empty()){
            int level = rottenOranges.size();

            for(int l=0; l<level; l++){
                pair<int,int> rottenOrange = rottenOranges.front();
                rottenOranges.pop();

                for(auto dir: directions){
                    int i = rottenOrange.first + dir[0];
                    int j = rottenOrange.second + dir[1];

                    if(i>=0 && i<rows && j>=0 && j< cols && grid[i][j]==1){
                        grid[i][j] = 2;
                        rottenOranges.push({i,j});
                        freshOranges--;
                    }
                }
            }
            time++;
        }

        return freshOranges == 0 ? time : -1;
    }
};