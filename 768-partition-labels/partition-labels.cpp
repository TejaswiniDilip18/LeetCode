class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> map;
        vector<int> result;
        for(int i=0; i<s.size(); i++){
            map[s[i]] = i;
        }

        int left=0, right= 0;
        for(int i=0; i<s.size(); i++){
            if(map[s[i]] > right) right = map[s[i]];
            if(i==right){
                result.push_back(right-left+1);
                left = right+1;
            }
        }
        return result;
    }
};