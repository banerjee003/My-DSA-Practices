class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int>m;
        
        vector<int>ans;
        
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
            
            if(i == k-1) ans.push_back(m.size());
            
            if(i >= k){
                m[arr[i-k]]--;
                
                if(m[arr[i-k]] == 0) 
                    m.erase(arr[i-k]);
                
                ans.push_back(m.size());
            }
        }
        return ans;
    }
};
