class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        longest_substr = set()
        l, r = 0, 0
        max_len = 0
        
        while r < len(s):
            while s[r] in longest_substr:
                longest_substr.remove(s[l])
                l += 1

            max_len = max(max_len, r-l+1)
            longest_substr.add(s[r])
            r += 1
        
        return max_len