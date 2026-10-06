class Solution {
public:
    string smallestSubsequence(string s) {
        int freq[26] = {0};
        bool visited[26] = {false};
        stack<char>st;

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a']--;
            if(visited[s[i] - 'a']){
                continue;
            }

            while(!st.empty() and s[i] < st.top() and freq[st.top() - 'a'] > 0){
                visited[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        
        string ans="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
