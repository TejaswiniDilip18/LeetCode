class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_substr = dict()
        l, r = 0, 0
        max_len = 0
        
        while r < len(s):
            if longest_substr.get(s[r]) != None and l <= longest_substr[s[r]]:
                l = longest_substr[s[r]] + 1

            max_len = max(max_len, r-l+1)
            longest_substr[s[r]] = r
            r += 1
        
        return max_len