class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>freq(26,0);
        
        for(int i = 0; i < n; i++){
            freq[word[i] - 'a']++;
        }

        sort(freq.begin(), freq.end(), [](const int &a, const int &b){
            return a > b;
        });
        
        int ans = 0;

        for(int i = 0; i < 26 and freq[i] > 0; i++){
            ans += freq[i] * ((i / 8) + 1);
        }
        return ans;
    }
};
