class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char,int>>st;
        vector<bool>remove(n, false);
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push({'(',i});
            }
            if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                } 
                else{
                    remove[i] = true;
                }
            }
        }
        while(!st.empty()){
            remove[st.top().second] = true;
            st.pop();
        }

        string ans = "";

        for(int i = 0; i < n; i++){
            if(!remove[i]){
                ans += s[i];
            }
        }
        return ans;
    }
};
