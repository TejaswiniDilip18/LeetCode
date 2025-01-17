class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
        return {};
        }
        
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i=0; i<intervals.size()-1; i++){
            if(result[result.size()-1][1] >= intervals[i+1][0]){
                result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i+1][1]);
            }
            else result.push_back(intervals[i+1]);
        }

        return result;
    }
};