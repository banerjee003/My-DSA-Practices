

class Solution {
  public:
    string encryptString(string s) {
        // code here
        int count = 1;
        string ans = "";
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i-1]){
                ans += s[i-1];
                ans += to_string(count);
                count = 1;
            }
            else{
                count++;
            }
        }
        ans += s.back();
        ans += to_string(count);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
