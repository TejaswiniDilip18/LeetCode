class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxArea = INT_MIN;

        while(l<r){
            int currArea = min(height[l], height[r])*(r-l);
            maxArea = max(maxArea, currArea);
            if(height[l] < height[r]) l++;
            else r--;
        }
        return maxArea;
    }
};