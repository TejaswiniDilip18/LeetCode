class Solution {
public:
    void findSum(int idx, int prev, int target, vector<int>& candidates, vector<int>& temp, set<vector<int>>& result){
        if(target==0){
            result.insert(temp);
            return;
        }
        if(idx==candidates.size()) return;

        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            findSum(idx+1, candidates[idx],target-candidates[idx], candidates, temp, result);
            temp.pop_back();
        }
        if(prev==candidates[idx]) return;
        findSum(idx+1, prev, target, candidates, temp, result);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findSum(0, -1, target, candidates, temp, result);
        vector<vector<int>> finalResult;

        for(auto& r: result){
            finalResult.push_back(r);
        }
        return finalResult;
    }
};