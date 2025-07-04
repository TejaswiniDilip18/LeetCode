class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        checkSum = {}
        for i in range(len(nums)):
            num = target - nums[i]
            if num in checkSum:
                return [i, checkSum.get(num)]
            checkSum[nums[i]] = i
        return [-1, -1]