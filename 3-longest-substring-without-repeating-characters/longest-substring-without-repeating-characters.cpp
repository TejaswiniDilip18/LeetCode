class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int l = 0;
        int r = 0;
        int max_len = 0;
        int n = s.size();
        std::unordered_map<char, int> str_map;

        while(r<n){
            if(str_map.find(s[r]) != str_map.end()){
                if(str_map[s[r]] >= l){
                    l = str_map[s[r]] + 1;
                }
            }
            max_len = max(max_len, r-l+1);
            str_map[s[r]] = r;
            r++;
        }
        return max_len;
    }
};