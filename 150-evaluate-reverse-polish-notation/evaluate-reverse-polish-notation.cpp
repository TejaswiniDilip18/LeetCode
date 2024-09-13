class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result;
        stack<int> numbers;

        for(auto c: tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int b = numbers.top(); 
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                
                if(c=="+") result = a + b;
                else if(c=="-") result = a - b;
                else if(c=="*") result = a * b;
                else if(c=="/") result = a / b;

                numbers.push(result);
            }
            else {
                numbers.push(std::stoi(c));
            }
        }

        return numbers.top();
    }
};