class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int>freq1(26,0);
        for(char c : s1){
            freq1[c - 'a']++;
        }

        int right = s1.size();
        int left = 0;

        vector<int>freq2(26,0);
        for(int i = 0; i < right; i++){
            freq2[s2[i] - 'a']++;
        }

        while(right < s2.size()){
            bool isSame = true;
            for(int i = 0; i < 26; i++){
                if(freq1[i] != freq2[i]){
                    isSame = false;
                    break;
                }
            }
            if(isSame){
                return true;
            }

            freq2[s2[left] - 'a']--;
            freq2[s2[right] - 'a']++;
            left++;
            right++;
        }

        for(char c : s1){
            if(freq1[c - 'a'] != freq2[c - 'a']){
                return false;
            }
        }
        return true;
    }
};
