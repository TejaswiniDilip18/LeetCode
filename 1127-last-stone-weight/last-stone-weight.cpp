class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int& st: stones){
            maxHeap.push(st);
        }

        while(maxHeap.size() > 1){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if(x != y) maxHeap.push(x-y);
        }

        if(maxHeap.empty()) return 0;
        else return maxHeap.top();

    }
};