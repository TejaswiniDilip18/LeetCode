class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort intervals array as per start time 
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        int i=0;
        while(i<intervals.size()){
            //check if the current interval overlaps with last interval,
            // if yes, merge them; else, add the interval to result
            if(intervals[i][0] <= result[result.size()-1][1]){
                result[result.size()-1][1] = max({result[result.size()-1][1], intervals[i][1]});
            }
            else result.push_back(intervals[i]); 
            i++;
        }
        return result;
    }
};