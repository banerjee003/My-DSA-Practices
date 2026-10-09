
class Solution {
public:
    int minInsertions(string s) {
        int need = 0;
        int insertion = 0;

        for (char c : s) {
            if (c == '(') {
                if (need % 2 == 1) {
                    insertion++;
                    need--;
                }
                need += 2;
            } else {
                need--;

                if (need < 0) {
                    insertion++;
                    need = 1;
                }
            }
        }

        return insertion + need;
    }
};
