class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        num_set = set(nums)
        max_count = 0

        for num in num_set:
            if num-1 not in num_set:
                count = 1
                curr = num

                while curr+1 in num_set:
                    curr += 1
                    count += 1
                    
                max_count = max(count, max_count)
        
        return max_count