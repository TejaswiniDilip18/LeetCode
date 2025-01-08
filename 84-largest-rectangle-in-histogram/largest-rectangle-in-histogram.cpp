class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int h = heights.size();
        
        if(h==1){
            return heights[0];
        }

        int area = INT_MIN;
        stack<int> prevSmall, nextSmall;
        vector<int> prev(h,-1);
        vector<int> next(h,h);

        for(int i=0; i < h; i++){
            while(!prevSmall.empty() && heights[prevSmall.top()] >= heights[i]){
                prevSmall.pop();
            }
            if(!prevSmall.empty()) prev[i] = prevSmall.top();
            prevSmall.push(i);
        }
        for(int j=h-1; j>=0; j--){
            while(!nextSmall.empty() && heights[nextSmall.top()] >= heights[j]){
                nextSmall.pop();
            }
            if(!nextSmall.empty()) next[j] = nextSmall.top();
            nextSmall.push(j);
        }

        for(int i=0; i < h; i++){
            int currArea = heights[i] * (next[i] - prev[i] - 1);
            area = max(area, currArea);
        }        
        return area;
    }
};