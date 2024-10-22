class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = INT_MIN;
        int left = 0;
        int right = height.size() - 1;

        while(left < right){
            int currArea = (right-left)*min(height[left], height[right]);
            area = max(area, currArea);
            if(height[left] < height[right]) left ++;
            else right --;
        }
        return area;
    }
};