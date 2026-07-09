
class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        unordered_map<char, int>m;
        
        for(char i : s){
            m[i]++;
        }
        
        for(auto i : s){
            if(m[i] == 1){
                return i;
            }
        }
        return '$';
    }
};
