class Solution {
  public:
    string toggleCase(string &s) {
        // code here
        string ans = "";
        
        for(auto i : s){
            if(i >= 'A' and i <= 'Z'){
                ans += tolower(i);
            }
            if(i >= 'a' and i <= 'z'){
                ans += toupper(i);
            }
        }
        return ans;
    }
};
