class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        unordered_map<char,int>m;
        int maxLen = 0;

        for(int right = 0; right < n; right++){
            m[s[right]]++;
            
            if(m[s[right]] >= 1){
                while(m[s[right]] > 1){
                    m[s[left]]--;
                    left++;
                }
            }
            maxLen = max(maxLen, (right - left + 1));
        }

        return maxLen;
    }
};