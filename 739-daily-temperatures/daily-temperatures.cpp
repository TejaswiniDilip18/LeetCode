class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> temp;
        for(int i=0; i<temperatures.size(); i++){
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()]){
                answer[temp.top()] = i - temp.top();
                temp.pop();
            }

            temp.push(i);
        }
        return answer;
    }
};