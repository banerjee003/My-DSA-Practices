class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int high = 0;
        for(int i; i< arr.size(); i++){
            if(arr[i] > arr[high]){
                high = i;
            }
        }
        return high;
    }
};