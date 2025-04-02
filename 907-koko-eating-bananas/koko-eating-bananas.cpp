class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left <= right){
            int mid = (left+right)/2;
            long hours=0;
            for(int i=0; i<piles.size(); i++){
                hours += ceil((double)piles[i]/(double)mid);
            }
            if(hours <= h) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};