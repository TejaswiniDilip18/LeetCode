class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        queue<int> q;

        for(auto& p: prerequisites){
            adj[p[1]].push_back(p[0]);
        }

        for(int i=0; i<numCourses; i++){
            for(auto& a: adj[i]){
                indegree[a]++;
            }
        }

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;

        while(!q.empty()){
            auto course = q.front();
            q.pop();
            count++;
            for(auto& a: adj[course]){
                indegree[a]--;

                if(indegree[a]==0)
                    q.push(a);
            }
        }
        if(count==numCourses) return true;
        return false;
    }
};