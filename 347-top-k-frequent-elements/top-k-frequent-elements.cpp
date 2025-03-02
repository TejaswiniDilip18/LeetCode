class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto& [num, freq]: mp){
            pq.push({freq, num});
            if(pq.size()>k) pq.pop();
        }

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};