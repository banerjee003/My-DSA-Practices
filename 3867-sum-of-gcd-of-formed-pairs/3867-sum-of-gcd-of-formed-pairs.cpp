class Solution {
public:
    int getGcd(int n, int m){
        int gcd = 1;
        for(int i = 2; i <= min(n,m); i++){
            if(n % i == 0 and m % i == 0){
                gcd = i;
            }
        }
        return gcd;
    }

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd(n,0);

        int m = nums[0];
        for(int i = 0; i < n; i++){
            m = max(m, nums[i]);
            int g = gcd(m, nums[i]);
            prefixGcd[i] = g;
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int i = 0, j = n-1;
        long long sum = 0;
        while(i < j){
            int g = gcd(prefixGcd[i], prefixGcd[j]);
            sum += g;
            i++;
            j--;
        }
        return sum;
    }
};
