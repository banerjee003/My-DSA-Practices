class Solution {
public:
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
