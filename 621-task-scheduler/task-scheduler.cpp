class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int hashMap[26] = {0};
        int cpu = 0;

        for(char& ch: tasks){
            hashMap[ch - 'A']++;
        }

        priority_queue<pair<int,int>> maxHeap; // {freq, char}
        for(int i=0; i<26; i++){
            if(hashMap[i] !=0) 
                maxHeap.push({hashMap[i], i});
        }

        while(!maxHeap.empty()){
            vector<pair<int,int>> temp;
            int cycle = 0;

            for(int i=0; i<=n; i++){
                if(!maxHeap.empty()){
                    auto [freq, num] = maxHeap.top();
                    maxHeap.pop();
                    freq--;
                    if(freq > 0) temp.push_back({freq, num});
                    cycle++;
                }                               
            }

            for(auto& t: temp){
                maxHeap.push(t);
            }

            if(maxHeap.empty()) cpu += cycle;
            else cpu += n+1;

        }
        return cpu; 
    }
};