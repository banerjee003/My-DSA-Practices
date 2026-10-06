class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int curr = i/8;
            ans += curr + 1;
        }
        return ans;
    }
};
