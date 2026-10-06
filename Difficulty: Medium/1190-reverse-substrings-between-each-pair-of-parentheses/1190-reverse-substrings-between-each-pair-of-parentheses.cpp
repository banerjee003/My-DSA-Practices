class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string curr = "";

        for(char ch : s){
            if(ch == '('){
                st.push(curr);
                curr = "";
            }
            else if(ch == ')'){
                reverse(curr.begin(), curr.end());

                string prev = st.top();
                st.pop();

                curr = prev + curr;
            }
            else{
                curr += ch;
            }
        }
        return curr;
    }
};