class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<pair<int, int>>p;
        int n = capacity.size();

        for(int i = 0; i < n; i++){
            int rem = capacity[i] - rocks[i];
            p.push_back({rem,i});
        }

        sort(p.begin(), p.end(), [](const pair<int,int>&a, const pair<int,int>&b){
            return a.first < b.first;
        });

        int count = 0;
        for(int i = 0; i < n; i++){
            if(additionalRocks >= p[i].first){
                additionalRocks -= p[i].first;
                count++;
            }
        }
        return count;
    }
};
