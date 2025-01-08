class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        unordered_map<int,int> greaterMap;
        stack<int> st;

        for(int j= nums2.size()-1; j>=0; j--){
            while(!st.empty() && st.top()<= nums2[j]){
                st.pop();
            }
            if(st.empty()){
                greaterMap[nums2[j]] = -1;
            }
            else greaterMap[nums2[j]] = st.top();

            st.push(nums2[j]);
        }

        for(int i=0; i<nums1.size(); i++){
            if(greaterMap.find(nums1[i]) != greaterMap.end()){
                result[i] = greaterMap[nums1[i]];
            }
        }
        
        return result;
    }
};