class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,long int>> adj[n];
        
        for(auto r: roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        
        priority_queue<pair<long int,int>, vector<pair<long int,int>>, greater<pair<long int,int>>> pq;
        vector<long int> dist(n, LONG_MAX);
        vector<int> ways(n, 1);
        
        dist[0] = 0;
        pq.push({0, 0});
        // ways[0]=1;
        
        int mod = 1e9 + 7;
        
        while(!pq.empty()){
            long int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto a: adj[node]){
                int adjNode = a.first;
                long int adjDist = a.second;
                
                if(d+adjDist < dist[adjNode]){
                    dist[adjNode] = d + adjDist;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(d+adjDist == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
                
            }
        }
        
        return ways[n-1];
    }
};