class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freqMap;
        std::priority_queue<std::pair<int, int>> maxHeap;
        std::vector<int> result;

        for(int num: nums){
            freqMap[num]++;
        }

        for(const auto& [num, freq]: freqMap){
            maxHeap.push({freq,num});
        }

        for(int i=0; i< k; i++){
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};