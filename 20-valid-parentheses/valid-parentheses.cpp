class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2 != 0) return false;
        
        stack<char> st;

        for(auto ch: s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char t = st.top();
                st.pop();
                if((ch == ')' && t != '(') || (ch == ']' && t != '[') || (ch == '}' && t != '{')) 
                    return false;
            }
        }
        return st.empty();
    }
};