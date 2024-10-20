class Solution {
public:
    // sort by ascending order of end time
    static bool sortEndTime(vector<int>& a, const vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;

        sort(intervals.begin(), intervals.end(), sortEndTime);

        int prevEnd = intervals[0][1];

        for(int i=1; i< intervals.size(); i++){
            if(intervals[i][0] < prevEnd){
                count++;
            }
            else{
                prevEnd = intervals[i][1];
            }
        }
        return count;
    }
};