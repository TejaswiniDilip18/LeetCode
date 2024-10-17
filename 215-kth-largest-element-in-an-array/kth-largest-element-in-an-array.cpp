class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue <int> min_Heap;

        for(int num: nums){
            min_Heap.push(num);
        }
        for(int i=0; i<k-1; i++){
            min_Heap.pop();
        }

        return min_Heap.top();
    }
};