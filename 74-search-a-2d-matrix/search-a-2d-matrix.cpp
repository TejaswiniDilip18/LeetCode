class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size()-1;
        int cols = matrix[0].size()-1;

        int low = 0;
        int high = rows;

        while(low <= high){
            int midRow = (low+high)/2;

            if(target >= matrix[midRow][0] && target <= matrix[midRow][cols]){
                int left = 0;
                int right = cols;
                // binary search on midRow
                while(left<=right){
                    int mid = (left+right)/2;
                    if(target == matrix[midRow][mid]) return true;
                    else if(target > matrix[midRow][mid]) left = mid+1;
                    else right = mid-1;
                }
                return false;
            }
            else if(target > matrix[midRow][cols]){
                low = midRow+1;
            }
            else{
                high = midRow-1;
            }

        }
        return false;
    }
};