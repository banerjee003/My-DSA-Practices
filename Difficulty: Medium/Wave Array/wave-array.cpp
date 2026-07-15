class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        int n = arr.size();
        n /= 2;
        n *= 2;
        for(int i = 0; i < n-1; i+=2){
            swap(arr[i],arr[i+1]);
        }
    }
};
