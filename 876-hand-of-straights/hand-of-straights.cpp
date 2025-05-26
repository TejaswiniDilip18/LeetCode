class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;

        sort(hand.begin(), hand.end());

        unordered_map<int,int> count;
        for(int& card: hand){
            count[card]++;
        }

        for(int card: hand){
            if(count[card] > 0){ 
                for(int i=0; i<groupSize; i++){
                    if(count.find(card+i) == count.end() || count[card+i] <= 0) return false;
                    else count[card+i]--;
                }
            }
        }
        return true;
    }
};