class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int count = 0;

        string ans = "";

        for(int right = 0; right < n; right++){
            if(s[right] == '1'){
                count++;
            }

            while(count > k){
                if(s[left] == '1'){
                    count--;
                }
                left++;
            }

            if(count == k){
                while(s[left] == '0'){
                    left++;
                }

                string curr = s.substr(left, right-left+1);

                if(ans.empty() || curr.size() < ans.size() || (curr.size() == ans.size() && curr < ans)){
                    ans = curr;
                }
            }
        }

        return ans;
    }
};
