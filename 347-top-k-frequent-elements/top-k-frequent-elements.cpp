class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        vector<int> result;

        // get the frequency map
        for(int i=0; i < nums.size(); i++){
            countMap[nums[i]]++;
        }

        // use min heap to store elements by frequency
        for(auto m: countMap){
            minHeap.push({m.second, m.first});
            if(minHeap.size()>k) minHeap.pop();
        }

        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};