class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> strMap;
        int maxLen = 0;
        int left = 0;
        int right = 0;

        while(right < s.length()){
            if(strMap.find(s[right]) != strMap.end() && strMap[s[right]] >= left){
                left = strMap[s[right]]+1;
            }
            maxLen = max(maxLen, right-left+1);
            strMap[s[right]] = right;
            right++;
        }

        return maxLen;
    }
};