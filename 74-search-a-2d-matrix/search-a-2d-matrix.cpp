class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size()-1;
        int cols = matrix[0].size()-1;
        int low = 0, high = rows;
        
        while(low <= high){
            int mid_row = (low+high)/2;
            
            if(target >= matrix[mid_row][0] && target <= matrix[mid_row][cols]){ 
                int l = 0, r = cols;
                while(l<=r){
                    int mid = (l+r)/2;
                    if(matrix[mid_row][mid] == target) return true;
                    else if(matrix[mid_row][mid] < target) l = mid+1;
                    else r = mid - 1;
                }
                return false;
            }
            else if(matrix[mid_row][cols] < target) low = mid_row + 1;
            else high = mid_row - 1;
        }
        return false;
    }
};