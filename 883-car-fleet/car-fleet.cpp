class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> pos;
        int fleetCount = 0;

        for(int i=0; i<n; i++){
            double time = (double)(target - position[i]) / speed[i];
            pos.push_back({position[i], time});
        }
        sort(pos.rbegin(), pos.rend());

        double lastTime = 0;

        for(int i=0; i<n; i++){
            if(pos[i].second > lastTime){
                fleetCount++;
                lastTime = pos[i].second;
            }
        }
        return fleetCount;
    }
};