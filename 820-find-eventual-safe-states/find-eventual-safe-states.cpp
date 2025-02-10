class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n,0);
        vector<vector<int>> revGraph(n);

        for(int i=0; i<n; i++){
            for(int it: graph[i]){
                revGraph[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> Q;
        
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                Q.push(i);
            }
        }

        vector<int> safeNodes;

        while(!Q.empty()){
            int t = Q.front();
            Q.pop();
            safeNodes.push_back(t);

            for(auto it: revGraph[t]){
                indegree[it]--;
                if(indegree[it]==0) Q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};