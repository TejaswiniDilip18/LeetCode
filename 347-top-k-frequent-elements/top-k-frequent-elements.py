class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        numsCounter = Counter(nums)
        return heapq.nlargest(k, numsCounter.keys(), key= numsCounter.get)