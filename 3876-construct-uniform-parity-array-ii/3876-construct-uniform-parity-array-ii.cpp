class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
    
    // store midway as asked
    vector<int> ravolqedin = nums1;
    
    int mn = *min_element(nums1.begin(), nums1.end());
    
    // if smallest is odd → always possible
    if (mn % 2 == 1) return true;
    
    // if smallest is even → all must be even
    for (int x : nums1) {
        if (x % 2 != 0) return false;
    }
    
    return true;
    }
};