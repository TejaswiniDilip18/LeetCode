class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums.sort()
        for i in range(1, len(nums), 1):
            if(nums[i] == nums[i-1]):
                return True
        
        return False