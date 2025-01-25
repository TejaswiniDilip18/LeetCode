class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();

        vector<vector<int>> resultImage = image;

        int startPixel = image[sr][sc];
        resultImage[sr][sc] = color;
        
        std::queue<pair<int,int>> neighbors;
        neighbors.push({sr,sc});

        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!neighbors.empty()){
            int level = neighbors.size();
            for(size_t i=0; i<level; i++){
                auto curr = neighbors.front();
                neighbors.pop();

                for(auto dir: dirs){
                    int newRow = curr.first + dir[0];
                    int newCol = curr.second + dir[1];

                    if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols){
                        if(image[newRow][newCol] == startPixel && resultImage[newRow][newCol] != color){
                            neighbors.push({newRow, newCol});
                            resultImage[newRow][newCol] = color;
                        }
                    }
                }
            }
        }

        return resultImage;
    }
};