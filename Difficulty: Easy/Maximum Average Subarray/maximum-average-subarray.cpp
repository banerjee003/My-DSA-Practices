class Solution {
  public:
    int findMaxAverage(vector<int>& arr, int k) {
        // code here
        double maxavg = INT_MIN;
        int sum = 0;
        int idx;
        for(int i = 0; i < arr.size(); i++){
            if(i < k){
                sum += arr[i];
            }
            
            if(i == k-1){
                if(sum/double(k) > maxavg) idx = i-k+1;
                maxavg = max(sum/double(k), maxavg);
            }
            
            if(i >= k){
                sum -= arr[i-k];
                sum += arr[i];
                if(sum/double(k) > maxavg) idx = i-k+1;
                maxavg = max(sum/double(k),maxavg);
            }
        }
        return idx;
    }
};
