class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False
        
        # counts = [0]*26
        
        # for i in range(len(s)):
        #     counts[ord(s[i]) - ord('a')] += 1
        #     counts[ord(t[i]) - ord('a')] -= 1
        
        # for count in counts:
        #     if(count != 0):
        #         return False

        s_dict = {}
        t_dict = {}

        for i in range(len(s)):
            s_dict[s[i]] = 1 + s_dict.get(s[i], 0)
            t_dict[t[i]] = 1 + t_dict.get(t[i], 0)
        
        return s_dict == t_dict