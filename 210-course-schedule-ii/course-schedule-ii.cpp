class Solution {
public:
    bool dfs(int course, vector<vector<int>>& adj, vector<int>& isExplored, stack<int>& st){
        if(isExplored[course]==1) return false; // node is already visited, cycle exists
        if(isExplored[course]==2) return true; // node is already processed

        isExplored[course] = 1; // mark visited
        for(int c: adj[course]){
            if(!dfs(c, adj, isExplored, st)){
                return false;
            }
        }

        isExplored[course] = 2; // mark processed
        st.push(course);

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
        stack<int> st;

        for(int i=0; i < numCourses; i++){
            if(isExplored[i]==0){
                if(!dfs(i, adj, isExplored, st))
                    return {};
            }
        }
        // reverse(result.begin(), result.end());
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};