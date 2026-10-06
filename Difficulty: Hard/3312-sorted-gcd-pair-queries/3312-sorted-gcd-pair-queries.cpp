class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        unordered_map<int,int>freq;
        int mx = *max_element(nums.begin(), nums.end());

        for(int x: nums){
            freq[x]++;
        }

        vector<long long>cntDiv(mx+1, 0);
        for(int i=1; i <= mx; i++){
            for(int mul = i; mul <= mx; mul += i){
                cntDiv[i] += freq[mul];
            }
        }

        vector<long long>exact(mx+1, 0);
        for(int i = mx; i >= 1; i--){
            long long cnt = cntDiv[i];
            exact[i] = (cnt * (cnt-1)) / 2;

            for(int multiple = 2*i; multiple <= mx; multiple += i){
                exact[i] -= exact[multiple];
            }
        }

        vector<long long>prefix;
        vector<int>gcdVal;

        long long sum = 0;
        for(int i = 1; i <= mx; i++){
            if(exact[i] > 0){
                sum += exact[i];
                prefix.push_back(sum);
                gcdVal.push_back(i);
            }
        }

        vector<int>ans;

        for(long long q : queries){
            int idx = lower_bound(prefix.begin(), prefix.end(), q + 1) - prefix.begin();
            ans.push_back(gcdVal[idx]);
        }
        return ans;
    }
};
