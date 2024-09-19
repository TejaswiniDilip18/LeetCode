class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> temp;
        for(int i=0; i<temperatures.size(); i++){
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