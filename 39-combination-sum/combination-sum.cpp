class Solution {
public:
    void findSum(vector<int>& candidates, int target, int idx, vector<int> temp, vector<vector<int>>& result){
        if(idx==candidates.size()){
            if(target==0) result.push_back(temp);
            return;
        }

        if(target >= candidates[idx])
        {
            temp.push_back(candidates[idx]);
            findSum(candidates, target-candidates[idx], idx, temp, result);
            temp.pop_back();
        }
        findSum(candidates, target, idx+1, temp, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        findSum(candidates, target, 0, temp, result);
        return result;
    }
};