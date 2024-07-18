class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n= nums2.size();
        int i =0, j=0;
        vector<int> merged_array;
        merged_array.reserve(m + n);

        // Merge the two sorted arrays
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged_array.push_back(nums1[i++]);
            } else {
                merged_array.push_back(nums2[j++]);
            }
        }

        // If there are remaining elements in nums1
        while (i < m) {
            merged_array.push_back(nums1[i++]);
        }

        // If there are remaining elements in nums2
        while (j < n) {
            merged_array.push_back(nums2[j++]);
        }


        int size = merged_array.size();
        int mid = size/2;


        if(size%2 == 0){
            return (merged_array[mid] + merged_array[mid-1])/2.0;
        }
        else 
            return merged_array[mid];
    }
};