class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        int left = 0;
        int right = intervals.size();

        while(left<right && intervals[left][1] < newInterval[0]){
            result.push_back(intervals[left]);
            left++;
        }

        while(left<right && intervals[left][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[left][0]);
            newInterval[1] = max(newInterval[1], intervals[left][1]);
            left++;
        }

        result.push_back(newInterval);

        while(left<right){
            result.push_back(intervals[left]);
            left++;
        }
        return result;
    }
};