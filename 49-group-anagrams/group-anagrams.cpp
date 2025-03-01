class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<int>> mp;
        
        for(int i=0; i<strs.size(); i++){
            string st = strs[i];
            sort(st.begin(), st.end());
            mp[st].push_back(i);
        }

        for(auto m: mp){
            vector<int> idxs = m.second;
            vector<string> temp;
            for(int idx: idxs){
                temp.push_back(strs[idx]);
            }
            result.push_back(temp);
        }

        return result;
    }
};