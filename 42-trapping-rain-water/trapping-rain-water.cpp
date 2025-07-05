class Solution {
public:
    // int trap(vector<int>& height) {
    //     int n = height.size();

    //     vector<int> prefixMax(n);
    //     prefixMax[0] = height[0];
    //     for(int i=1; i<n; i++){
    //         prefixMax[i] = max(prefixMax[i-1], height[i]);
    //     }

    //     vector<int> suffixMax(n);
    //     suffixMax[n-1] = height[n-1];
    //     for(int i=n-2; i>=0; i--){
    //         suffixMax[i] = max(suffixMax[i+1], height[i]);
    //     }

    //     int trappedWater = 0;
    //     for(int i=1; i<n-1; i++){
    //         int currVol = min(prefixMax[i-1], suffixMax[i+1]) - height[i];
    //         if(currVol > 0) trappedWater += currVol;
    //     }
    //     return trappedWater;
    // }

    // Optimal solution
    int trap(vector<int>& height){
        int l = 0;
        int r = height.size()-1;
        int leftMax = height[l];
        int rightMax = height[r];
        int vol = 0;

        while(l<r){
            if(height[l] <= height[r]){
                l++;
                leftMax = max(leftMax, height[l]);
                vol += leftMax - height[l];
            }
            else{
                r--;
                rightMax = max(rightMax, height[r]);
                vol += rightMax - height[r];
            }
        }

        return vol;
    }
};