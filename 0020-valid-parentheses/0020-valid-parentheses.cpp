class Solution {
public:
    bool isValid(string st) {
        stack<char>s;
        for(char ch : st){
            if(ch == '(' || ch == '{' || ch == '['){
                s.push(ch);
            }
            if(ch == ')'){
                if(s.empty() || s.top() != '('){
                    return false;
                }
                s.pop();
            }
            if(ch == '}'){
                if(s.empty() || s.top() != '{'){
                    return false;
                }
                s.pop();
            }
            if(ch == ']'){
                if(s.empty() || s.top() != '['){
                    return false;
                }
                s.pop();
            }
        }
        return s.empty();
    }
};