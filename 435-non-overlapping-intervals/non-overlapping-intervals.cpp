class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];});

        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(prevEnd > intervals[i][0]){
                count++;
                continue;
            }
            prevEnd = intervals[i][1];
            
        }
        return count;
    }
};