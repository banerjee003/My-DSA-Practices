class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        // code here
        if(s1.size() != s2.size()) return false;
        
        unordered_map<char, int>m1;
        unordered_map<char, int>m2;
        
        for(int i = 0; i < s1.size(); i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        
        if(m1 == m2) return true;
        return false;
    }
};
