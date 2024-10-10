class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_map<int, int> num_map;
        std::stack<int> num_stack;

        for(int i= nums2.size()-1; i>=0; i--){
            // if top of stack is smaller than the array element, pop it
            while(!num_stack.empty() && num_stack.top()<=nums2[i]){
                num_stack.pop();
            }

            // top of stack is greater than array element
            if(!num_stack.empty()){
                num_map[nums2[i]] = num_stack.top();
            }
            else{
                num_map[nums2[i]] = -1;
            }

            num_stack.push(nums2[i]);
        }

        std::vector<int> result(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            result[i] = num_map[nums1[i]];
        }

        return result;
    }
};