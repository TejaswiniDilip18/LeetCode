class Solution {
public:
    bool isValid(string s) {
        // exit if number of characters is odd
        if(s.size() % 2 != 0) return false;

        stack<char> para;

        for(char c: s){
            if(c == '(' || c == '{' || c == '[') para.push(c);
            else 
            {
                // check if stack is empty -if first char is closing bracket, then parantheses are not valid
                if(para.empty() || c == ')' && para.top() != '(' 
                    || c == '}' && para.top() != '{' 
                    || c == ']' && para.top() != '[' ) 
                    return false;

                para.pop();
            }
        }

        return para.empty();
    }
};