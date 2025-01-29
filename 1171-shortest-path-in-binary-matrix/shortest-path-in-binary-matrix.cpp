class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> dirs = {{-1,-1}, {-1,0}, {-1,1},{0,-1},{0,1}, {1, -1}, {1,0},{1,1}}; // 8 dir neighbors

        vector<vector<int>> dist(rows, vector<int>(cols,INT_MAX));

        queue<pair<int, pair<int,int>>> q;

        if(grid[0][0]==1 || grid[rows-1][cols-1] == 1){
            return -1;
        }

        dist[0][0] = 1;
        q.push({dist[0][0], {0,0}});

        while(!q.empty()){
            int currDist = q.front().first;
            auto [row, col] = q.front().second;
            q.pop();

            if(row==rows-1 && col==cols-1) return dist[row][col];

            for(auto dir: dirs){
                int i = row + dir[0];
                int j = col + dir[1];

                if(i>=0 && i<rows && j>=0 && j<cols && grid[i][j] == 0 && currDist+ 1 < dist[i][j]){
                    dist[i][j] = currDist + 1;
                    q.push({dist[i][j], {i,j}});
                }
            }
        }

        return dist[rows-1][cols-1]==INT_MAX ? -1: dist[rows-1][cols-1];
    }
};