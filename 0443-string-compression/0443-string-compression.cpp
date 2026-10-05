class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        string s = "";

        while(i < chars.size()){
            int count = 0;
            char c = chars[i];

            while(i < chars.size() && chars[i] == c){
                count++;
                i++;
            }

            s += c;
            if(count > 1){
                s += to_string(count);
            }
        }

        for(int i = 0; i < s.size(); i++){
            chars[i] = s[i];
        }

        return s.size();
    }
};