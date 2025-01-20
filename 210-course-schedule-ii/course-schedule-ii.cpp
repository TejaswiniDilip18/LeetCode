class Solution {
public:
    bool dfs(int course, vector<vector<int>>& adj, vector<int>& isExplored, vector<int>& result){
        if(isExplored[course]==1) return false; // node is already visited, cycle exists
        if(isExplored[course]==2) return true; // node is already processed

        isExplored[course] = 1; // mark visited
        for(int c: adj[course]){
            if(!dfs(c, adj, isExplored, result)){
                return false;
            }
        }

        isExplored[course] = 2; // mark processed
        result.push_back(course);

        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create adjacency list
        vector<vector<int>> adj(numCourses);

        for(auto& i: prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> isExplored(numCourses, 0);
        vector<int> result;

        for(int i=0; i < numCourses; i++){
            if(isExplored[i]==0){
                if(!dfs(i, adj, isExplored, result))
                    return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};