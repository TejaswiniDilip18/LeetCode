class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;

        for(int i=0; i<gas.size(); i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1;

        int start = 0, currGas = 0;
        for(int i=0; i<gas.size(); i++){
            currGas = currGas + gas[i] - cost[i];
            if(currGas < 0){
                start = i+1;
                currGas = 0;
            }
        }
        return start;
    }
};