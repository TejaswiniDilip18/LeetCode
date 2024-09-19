class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> temp;
        for(int i=0; i<n; i++){
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()]){
                int prev = temp.top();
                answer[prev] = i - prev;
                temp.pop();
            }

            temp.push(i);
        }
        return answer;
    }
};