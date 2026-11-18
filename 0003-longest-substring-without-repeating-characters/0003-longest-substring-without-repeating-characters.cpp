class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int n = s.size();
        int length = 0;
        unordered_map<char,int>m;

        for(int i = 0; i < n; i++){
            m[s[i]]++;
            if(m[s[i]] > 1){
                while(m[s[i]] > 1){
                    m[s[left]]--;
                    left++;
                }
            }
            length = max(length, i-left+1);
        }
        return length;
    }
};