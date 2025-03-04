class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> st;

        for(int i=temperatures.size()-1; i>=0; i--){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();

            if(!st.empty()) result[i] = st.top()-i;
            
            st.push(i);
        }
        return result;
    }
};