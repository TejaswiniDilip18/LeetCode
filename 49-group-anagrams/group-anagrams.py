class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        from collections import defaultdict

        anagrams = defaultdict(list)

        for st in strs:
            key = ''.join(sorted(st))
            anagrams[key].append(st)
        
        return list(anagrams.values())