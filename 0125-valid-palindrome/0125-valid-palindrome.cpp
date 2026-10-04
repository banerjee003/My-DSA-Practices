class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char ch : s){
            if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
                temp += ch;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                temp += (ch + 32);
            }
        }

        int n = temp.size();

        for(int i = 0; i < n/2; i++){
            if(temp[i] != temp[n-i-1])
                return false;
        }
        return true;
    }
};