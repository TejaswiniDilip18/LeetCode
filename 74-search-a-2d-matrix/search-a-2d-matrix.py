class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        low, high = 0, len(matrix) - 1

        while(low<=high):
            midRow = (low+high)//2
            if(target >= matrix[midRow][0] and target <= matrix[midRow][-1]):
                l, r = 0, len(matrix[0]) - 1              
                while(l<=r):
                    mid = (l+r)//2
                    if matrix[midRow][mid] == target:
                        return True
                    elif matrix[midRow][mid] > target: r = mid - 1
                    else: l = mid + 1

                return False

            elif target > matrix[midRow][-1]: low = midRow + 1
            else: high = midRow - 1
        
        return False
