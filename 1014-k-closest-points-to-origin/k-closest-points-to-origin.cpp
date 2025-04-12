class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxHeap;
        vector<vector<int>> closestPoints;

        for(vector<int>& point: points){
            int x = point[0];
            int y = point[1];
            int dist = (x*x) + (y*y);
            maxHeap.push({dist, point});
            if(maxHeap.size() > k) maxHeap.pop();
        }

        while(!maxHeap.empty()){
            closestPoints.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return closestPoints;
    }
};