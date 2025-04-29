class Solution {
public:
    void findSum(int idx, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& result){
        if(target==0){
            result.push_back(temp);
            return;
        }
        for(int i=idx; i<candidates.size(); i++){
            if(i>idx && candidates[i-1]==candidates[i]) continue;
            if(candidates[i] <= target){
                temp.push_back(candidates[i]);
                findSum(i+1, target-candidates[i], candidates, temp, result);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findSum(0, target, candidates, temp, result);
    
        return result;
    }
};