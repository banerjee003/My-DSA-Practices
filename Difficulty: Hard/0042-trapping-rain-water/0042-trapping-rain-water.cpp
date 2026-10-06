class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0] = -1;

        for(int i  = 1; i < n; i++){
            prefix[i] = max(prefix[i-1], height[i-1]);
        }

        suffix[n-1] = -1;
        for(int i = n-2; i >= 0; i--){
            suffix[i] = max(suffix[i+1], height[i+1]);
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            int curr = min(prefix[i], suffix[i]);
            if(curr > height[i]){
                total += (curr - height[i]);
            }
        }

        return total;
    }
};
