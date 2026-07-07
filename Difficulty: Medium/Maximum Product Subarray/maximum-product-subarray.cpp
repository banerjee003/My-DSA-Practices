class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size(); 
        
        if(n == 1 and arr[0] == 0) return 0;
        
        int prefix = 1, suffix = 1;
        int maxprod = INT_MIN;
        
        for(int i = 0; i < n; i++){
            
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            
            prefix = prefix*arr[i];
            suffix = suffix*arr[n-i-1];
            
            
            maxprod = max(maxprod, max(prefix,suffix));
        }
        return maxprod;
    }
};
