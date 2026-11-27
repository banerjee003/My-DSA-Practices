
class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size() || t.empty()) return "";

        int freq[128] = {0};

        for (char c : t) {
            freq[c]++;
        }

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        int missing = t.size();

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            if (freq[c] > 0) {
                missing--;
            }

            freq[c]--;

            while (missing == 0) {

                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                char ch = s[left];

                freq[ch]++;

                if (freq[ch] > 0) {
                    missing++;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";

        return s.substr(start, minLen);
    }
};
