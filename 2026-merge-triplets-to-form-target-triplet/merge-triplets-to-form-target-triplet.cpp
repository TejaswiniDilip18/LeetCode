class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> isPossible(3, false);
        for(int i=0; i<triplets.size(); i++){
            if (triplets[i][0] <= target[0] &&
                triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2]){

                if(triplets[i][0] == target[0]) isPossible[0] = true;
                if(triplets[i][1] == target[1]) isPossible[1] = true;
                if(triplets[i][2] == target[2]) isPossible[2] = true;
            }
        }

        return (isPossible[0] && isPossible[1] && isPossible[2]);
    }
};