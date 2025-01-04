class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        int len = s.length();
        unordered_map<char, int> str_map;

        while(right<len){
            if(str_map.find(s[right]) != str_map.end()){
                /* make sure duplicate is found at later position than current left position; 
                if we find duplicate before current position of left, no action is necessary
                */
                if(str_map[s[right]]>=left){
                    left = str_map[s[right]] + 1;
                }
            }
            max_len = max(max_len, (right-left+1));
            str_map[s[right]] = right;
            right++;
        }

        return max_len;
    }
};