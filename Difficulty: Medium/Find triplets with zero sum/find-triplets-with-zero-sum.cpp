class Solution {
  public:
    bool findTriplets(vector<int> &arr) {
        // code here
        if(arr.size() < 3) return false;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < arr.size()-2; i++){
            int sum = arr[i];
            int target = 0 - sum;
            unordered_map<int,int>m;
            for(int j = i+1; j < arr.size(); j++){
                int rem = target - arr[j];
                if(m.count(rem)){
                    return true;
                }
                m[arr[j]] = j;
            }
        }
        return false;
    }
};
