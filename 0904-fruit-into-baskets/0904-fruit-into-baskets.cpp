class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int>m;
        int ans = 0;
        int left = 0;
        
        for(int right = 0; right < n; right++){
            m[fruits[right]]++;

            while(m.size() > 2){
                m[fruits[left]]--;
                if(m[fruits[left]] == 0){
                    m.erase(fruits[left]);
                }
                left++;
            }

            if(m.size() <= 2){
                ans = max(ans, right-left+1);
            }
        }

        return ans;
    }
};
