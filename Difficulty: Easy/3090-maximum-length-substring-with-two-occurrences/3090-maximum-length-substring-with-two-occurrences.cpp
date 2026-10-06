class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int n = s.size();
        int maxLen = 0;
        unordered_map<char, int>m;

        for(int right = 0; right < n; right++){
            m[s[right]]++;

            if(m[s[right]] >= 2){
                while(m[s[right]] > 2){
                    m[s[left]]--;
                    left++;
                }
            }

            maxLen = max(maxLen, (right - left + 1));
        }

        return maxLen;
    }
};
