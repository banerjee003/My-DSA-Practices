class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int leftmax[n];
        int rightmax[n];
        int total = 0;
        
        for(int i = 0; i < n; i++){
            if(i == 0) leftmax[i] = arr[i];
            else leftmax[i] = max(leftmax[i-1], arr[i-1]);
        }
        
        for(int i = n-1; i >= 0; i--){
            if(i == n-1) rightmax[i] = arr[i];
            else rightmax[i] = max(rightmax[i+1], arr[i+1]);
        }
        
        for(int i = 0; i < n; i++){
            int m = min(rightmax[i], leftmax[i]);
            if(m > arr[i]){
                total += (m - arr[i]);
            }
        }
        return total;
    }
};

