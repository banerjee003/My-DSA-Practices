class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, ans = 0;
        for(char ch : s){
            if(ch == '('){
                left++;
            }
            else{
                if(left > 0){
                    left--;
                }
                else{
                    ans++;
                }
            }
        }
        return left+ans;
    }
};