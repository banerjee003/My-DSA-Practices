class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int,int>m;
        for(int i = 0; i < n2; i++){
            m[nums2[i]] = i;
        }

        vector<int>ans;

        for(int i = 0; i < n1; i++){
            int idx = m[nums1[i]] + 1;
            bool isFound = false;
            while(idx < n2){
                if(nums2[idx] > nums1[i]){
                    ans.push_back(nums2[idx]);
                    isFound = true;
                    break;
                }
                idx++;
            }
            if(!isFound){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
