class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        map<int,int>m;

        for(int i : nums){
            m[i]++;
        }

        int small = nums[0];
        int large = nums[nums.size()-1];

        vector<int>ans;
        for(int i = small; i <= large; i++){
            if(!m.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
