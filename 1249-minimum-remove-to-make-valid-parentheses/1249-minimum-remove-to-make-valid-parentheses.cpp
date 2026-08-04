class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        set<int>remove;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push({'(',i});
            }
            if(s[i] == ')'){
                if(!st.empty()){
                    st.pop();
                } 
                else{
                    remove.insert(i);
                }
            }
        }
        while(!st.empty()){
            remove.insert(st.top().second);
            st.pop();
        }

        string ans = "";

        for(int i = 0; i < s.size(); i++){
            if(remove.find(i) == remove.end()){
                ans += s[i];
            }
        }
        return ans;
    }
};
