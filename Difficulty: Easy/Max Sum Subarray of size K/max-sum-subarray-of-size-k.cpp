class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int currsum = 0;
        int maxsum = INT_MIN;
        
        for(int i = 0; i < arr.size(); i++){
            if(i < k){
                currsum += arr[i];
            }
            
            if(i == k-1) maxsum = currsum;
            
            if(i >= k){
                currsum += arr[i];
                currsum -= arr[i-k];
                maxsum = max(maxsum,currsum);
            }
        }
        return maxsum;
    }
};
