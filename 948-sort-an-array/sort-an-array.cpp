class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        std::vector<int> result;

        for(int n: nums){
            minHeap.push(n);
        }
        while(!minHeap.empty()){
            int n = minHeap.top();
            minHeap.pop();
            result.push_back(n);
        }
        return result;
    }
};