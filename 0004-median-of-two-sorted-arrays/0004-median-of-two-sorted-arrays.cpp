class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int>total;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                total.push_back(nums1[i]);
                i++;
            }
            else{
                total.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()){
            total.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            total.push_back(nums2[j]);
            j++;
        }

        for(int i : total){
            cout << i << " ";
        }

        int n = total.size();
        double ans;

        if(n % 2 == 0){
            ans = (total[n/2] + total[n/2 - 1]) / 2.0;
        }
        else{
            ans = 1.0 * total[n/2];
        }

        return ans;
    }
};
