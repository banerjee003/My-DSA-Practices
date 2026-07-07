class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int>m;
        int sum = 0;
        int len = 0;
        
        for(int i = 0; i < arr.size(); i++){
            sum += arr[i];
            
            if(sum == k) len = max(len,i+1);
            
            if(!m.count(sum)){
                m[sum] = i;
            }
            
            int rem = sum - k;
            
            if(m.count(rem)){
                len = max(len, (i-m[rem]));
            }
        }
        return len;
    }
};
