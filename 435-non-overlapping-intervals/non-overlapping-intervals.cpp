class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp =[](const auto& a, const auto&b){
            return a[1] < b[1];
        };
        sort(intervals.begin(), intervals.end(), comp);

        int intervalCount=0;
        int endTime = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < endTime) intervalCount++;
            else endTime = intervals[i][1];
        }
        return intervalCount;
    }
};