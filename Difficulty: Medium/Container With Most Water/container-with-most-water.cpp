class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int total = 0;
        
        while(left <= right){
            int curr = (right - left) * min(arr[left], arr[right]);
            
            if(arr[left] < arr[right]){
                left++;
            }
            else{
                right--;
            }
            
            total = max(total, curr);
        }
        return total;
    }
};
