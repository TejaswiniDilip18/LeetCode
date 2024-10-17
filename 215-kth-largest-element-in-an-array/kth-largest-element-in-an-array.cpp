class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue <int, std::vector<int>, std::greater<int>> min_Heap;

        for(int num: nums){
            min_Heap.push(num);

            if(min_Heap.size() > k){
                min_Heap.pop();
            }
        }

        return min_Heap.top();
    }
};