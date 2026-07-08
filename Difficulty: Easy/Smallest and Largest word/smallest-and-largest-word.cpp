class Solution {
  public:
    vector<string> smallerAndLarge(string &s) {
        int lc = INT_MIN, sc = INT_MAX;
        string lw = "", sw = "";
        string curr = "";
        int count = 0;

        for (int i = 0; i <= s.size(); i++) {

            if (i == s.size() || s[i] == ' ') {

                if (count > 0) {
                    if (count >= lc) {
                        lc = count;
                        lw = curr;
                    }

                    if (count < sc) {
                        sc = count;
                        sw = curr;
                    }
                }

                curr = "";
                count = 0;
            }
            else {
                curr += s[i];
                count++;
            }
        }

        return {sw, lw};
    }
};
