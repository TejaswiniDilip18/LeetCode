class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int,pair<int,int>>> maxHeap;

        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                int sum = nums1[i]+nums2[j];
                if(maxHeap.size()<k) maxHeap.push({sum, {nums1[i], nums2[j]}});
                else if(sum < maxHeap.top().first) {
                    maxHeap.pop();
                    maxHeap.push({sum, {nums1[i], nums2[j]}});
                }
                else if(sum >= maxHeap.top().first) break;
            }
        }

        while(!maxHeap.empty()){
            auto top = maxHeap.top();
            result.push_back({top.second.first, top.second.second});
            maxHeap.pop();
        }

        return result;
    }
};