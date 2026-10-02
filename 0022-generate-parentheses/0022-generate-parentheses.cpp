class Solution {
public:
    void makeParenthesis(string s, int open, int close, int n, vector<string>&ans){
        if(s.length() == 2 * n){
            ans.push_back(s);
            return;
        }

        if(open < n){
            s.push_back('(');
            makeParenthesis(s, open+1, close, n, ans);
            s.pop_back();
        }

        if(close < open){
            s.push_back(')');
            makeParenthesis(s, open, close+1, n, ans);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        makeParenthesis("", 0, 0, n, ans);
        return ans;
    }
};