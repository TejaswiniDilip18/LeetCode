class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        for(auto flight: flights){
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> price(n, INT_MAX);
        queue<pair<int, pair<int,int>>> q;

        price[src] = 0;
        q.push({0, {src, price[src]}}); // {stops, {src, price}}

        while(!q.empty()){
            auto flight = q.front();
            q.pop();
            int stops = flight.first;
            int currSrc = flight.second.first;
            int currPrice = flight.second.second;

            if(stops>k) continue;
           
            for(auto a: adj[currSrc]){
                int adjSrc = a.first;
                int adjPrice = a.second;
                
                if(stops<=k && price[adjSrc] > (currPrice + adjPrice)){
                    price[adjSrc] = currPrice + adjPrice;
                    q.push({stops+1, {adjSrc, price[adjSrc]}});
                }
            }
        }

        return price[dst]==INT_MAX ? -1: price[dst];
    }
};