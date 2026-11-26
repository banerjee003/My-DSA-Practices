class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right;
        int freq[26] = {0};
        int maxlen = 0, maxfreq = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++){
            freq[s[right]-'A']++;
            maxfreq = max(maxfreq, freq[s[right]-'A']);

            while(((right - left + 1) - maxfreq) > k){
                freq[s[left]-'A']--;
                maxfreq = 0;
                for(int i : freq){
                    maxfreq = max(maxfreq, i);
                }
                left++;
            }

            if(((right - left + 1) - maxfreq) <= k){
                ans = max(ans, right-left+1);
            }
        }

        return ans;
    }
};