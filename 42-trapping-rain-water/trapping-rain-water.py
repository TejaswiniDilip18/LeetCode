class Solution:
    def trap(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        maxL, maxR = height[l], height[r]
        vol = 0

        while l<r:
            if maxL <= maxR:
                l += 1
                maxL = max(maxL, height[l])
                vol += maxL - height[l]
            else:
                r -= 1
                maxR = max(maxR, height[r])
                vol += maxR - height[r]

        return vol