class Solution {
  public:
    string removeChars(string &s) {
        // code here
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= 'A' and s[i] <= 'Z') or (s[i] >= 'a' and s[i] <= 'z')){
                ans += s[i];
            }
        }
        return ans;
    }
};
