class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        unordered_map<int, int>m;

        for(int i : stones){
            if(i % 3 == 0){
                m[0]++;
            }
            else if(i % 3 == 1){
                m[1]++;
            }
            else{
                m[2]++;
            }
        }

        if(m[0] % 2 == 0){
            if(m[1] && m[2]){
                return true;
            }
        }
        else{
            if(abs(m[1] - m[2]) > 2){
                return true;
            }
        }

        return false;
    }
};
