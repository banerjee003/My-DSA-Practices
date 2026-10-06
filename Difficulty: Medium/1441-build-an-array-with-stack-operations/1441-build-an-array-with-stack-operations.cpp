class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int x = target.size();
        unordered_map<int,int>m;
        for(int i : target){
            m[i]++;
        }

        vector<string>ans;
        int count = 0;

        for(int i = 1; i <= n; i++){
            if(m[i] == 0){
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            else{
                ans.push_back("Push");
                if(i == target[x-1]){
                    break;
                }
            }

        }
        return ans;
    }
};
