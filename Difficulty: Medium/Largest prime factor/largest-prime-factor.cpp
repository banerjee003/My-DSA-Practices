class Solution {
public:
    int largestPrimeFactor(int n) {
        int ans = 1;

        while (n % 2 == 0) {
            ans = 2;
            n /= 2;
        }

        for (int i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                ans = i;
                n /= i;
            }
        }

        if (n > 2)
            ans = n;

        return ans;
    }
};
