class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;

        for(auto i : tokens){
            if(i != "+" && i != "-" && i != "*" && i != "/"){
                s.push(stoi(i));
            }
            else{
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();

                if(i == "+"){
                    s.push(a + b);
                }

                if(i == "-"){
                    s.push(a - b);
                }

                if(i == "*"){
                    s.push(a * b);
                }

                if(i == "/"){
                    s.push(a / b);
                }
            }
        }
        return s.top();
    }
};
