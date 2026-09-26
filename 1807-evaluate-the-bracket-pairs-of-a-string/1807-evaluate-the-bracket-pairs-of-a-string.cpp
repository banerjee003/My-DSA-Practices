class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        for(auto &x : knowledge){
            m[x[0]] = x[1];
        }

        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                i++;
                string key = "";
                while(s[i] != ')'){
                    key += s[i];
                    i++;
                }
                if(m.count(key)){
                    ans += m[key];
                }
                else{
                    ans += "?";
                }
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};