class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefixMax(n);
        prefixMax[0] = height[0];
        for(int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }

        vector<int> suffixMax(n);
        suffixMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        int trappedWater = 0;
        for(int i=1; i<n-1; i++){
            int currVol = min(prefixMax[i-1], suffixMax[i+1]) - height[i];
            if(currVol > 0) trappedWater += currVol;
        }
        return trappedWater;
    }
};