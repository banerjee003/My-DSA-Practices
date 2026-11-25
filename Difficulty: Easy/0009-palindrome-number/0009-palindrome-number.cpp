class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long long rev = 0;
        int original = x;
        while(original > 0){
            int rem = original % 10;
            rev *= 10;
            rev += rem;
            original /= 10;
        }
        return rev == x ? true : false;
    }
};
