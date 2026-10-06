class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int>m;
        vector<int>copy = arr;
        sort(copy.begin(), copy.end());

        int rank = 1;
        for(int i = 0; i < copy.size(); i++){
            if(!m.count(copy[i])){
                m[copy[i]] = rank;
                rank++;
            }
        }

        vector<int>ans;

        for(int i = 0; i < arr.size(); i++){
            ans.push_back(m[arr[i]]);
        }

        return ans;
    }
};
