class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int>m;
        for(char c : s){
            m[c]++;
        }

        string left = "";
        string mid = "";

        for(auto c : m){
            left += string(c.second/2, c.first);

            if(c.second % 2 != 0){
                mid += c.first;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
