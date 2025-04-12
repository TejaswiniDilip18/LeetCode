class KthLargest {
public:
    priority_queue<int, std::vector<int>, std::greater<int>> min_pq;
    int top_k;

    KthLargest(int k, vector<int>& nums) {
        top_k = k;
        for(int& num: nums){
            add(num);
        }
    }
    
    int add(int val) {
        // maintain min pq of size k
        if(min_pq.size() < top_k){
            min_pq.push(val);
        }
        else if(val > min_pq.top()){
            min_pq.push(val);
            min_pq.pop();
        }

        return min_pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */