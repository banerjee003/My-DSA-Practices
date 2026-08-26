class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        unordered_map<int,int>m;

        vector<int>ans;
        int i = 0;
        
        while(i < nums.size()){
            int idx = i;
            m[temp[i]] = idx;
            while((i < n-1) && (temp[i+1] == temp[i])){
                i++;
                m[temp[i]] = idx;
            }
            i++;
        }

        for(int i : nums){
            ans.push_back(m[i]);
        }

        return ans;
    }
};
