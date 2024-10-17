class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue <int> my_Heap;

        for(int num: nums){
            my_Heap.push(num);
        }
        for(int i=0; i<k-1; i++){
            my_Heap.pop();
        }

        return my_Heap.top();
    }
};