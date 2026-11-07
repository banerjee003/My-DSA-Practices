class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>first;
        stack<char>second;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(first.empty()) continue;
                first.pop();
            }
            else{
                first.push(s[i]);
            }
        }

        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#'){
                if(second.empty()) continue;
                second.pop();
            }
            else{
                second.push(t[i]);
            }
        }

        while(!first.empty() && !second.empty()){
            if(first.top() != second.top()){
                return false;
            }
            first.pop();
            second.pop();
        }

        if(first.empty() && second.empty()) return true;
        return false;
    }
};
