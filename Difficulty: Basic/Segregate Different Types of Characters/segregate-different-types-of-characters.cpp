class Solution {
  public:
    vector<string> splitString(string s) {
        // code here
        string one = "";
        string two = "";
        string three = "";
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' and s[i] <= 'Z'){
                one += s[i];
            }
            
            else if(s[i] >= 'a' and s[i] <= 'z'){
                one += s[i];
            }
            
            else if(s[i] >= '0' and s[i] <= '9'){
                two += s[i];
            }
            
            else{
                three += s[i];
            }
        }
        
        return {one,two,three};
    }
};
