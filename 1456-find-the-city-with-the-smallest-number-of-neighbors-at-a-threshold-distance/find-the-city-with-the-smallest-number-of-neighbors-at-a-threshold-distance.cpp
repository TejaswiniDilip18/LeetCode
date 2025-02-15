class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        for(auto edge: edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        
        for(int i = 0; i< n; i++){
            dist[i][i] = 0;
        }
        
        for(int mid = 0; mid < n; mid++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j< n; j++){
                    if(dist[i][mid] == INT_MAX || dist[mid][j] == INT_MAX) continue; // INT_MAX means node isn't reachable
                    
                    dist[i][j] = min(dist[i][j], (dist[i][mid] + dist[mid][j]));
                }
            }
        }
        
        int neighborsMin = n;
        int city = -1;
        
        for(int i = 0; i< n; i++){
            int count = 0;
            for(int j = 0; j< n; j++){
                // for each node at i, check if the dist is less than threshold for all other nodes
                if(dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count != 0 && count <= neighborsMin){
                neighborsMin = count;
                city = i;
            }
        }
        
        return city;
    }
};