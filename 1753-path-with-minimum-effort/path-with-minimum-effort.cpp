class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
                        greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));

        const int dirX[4] = {-1, 0, 1, 0};
        const int dirY[4] = {0, 1, 0, -1};

        effort[0][0] = 0;
        pq.push({effort[0][0], {0,0}});

        int maxEffort = INT_MIN;

        while(!pq.empty()){
            int currEffort = pq.top().first;
            auto [row, col] = pq.top().second;
            pq.pop();

            maxEffort = max(maxEffort, currEffort);

            if(row==rows-1 && col==cols-1) return maxEffort;

            for(int k=0; k<4; k++){
                int i = row + dirX[k];
                int j = col + dirY[k];

                if(i>=0 && i<rows && j>=0 && j<cols && abs(heights[i][j] - heights[row][col])< effort[i][j]){
                    effort[i][j] = abs(heights[i][j] - heights[row][col]);
                    pq.push({effort[i][j], {i,j}});
                }
            }
        }

        return maxEffort;
    }
};