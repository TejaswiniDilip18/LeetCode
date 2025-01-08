class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(),0);
        stack<int> s;

        for(int i=temperatures.size()-1; i>=0; i--){
            
            while(!s.empty() && temperatures[s.top()] <= temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                answer[i] = s.top() - i;
            }
            s.push(i);
        }

        return answer;
    }
};