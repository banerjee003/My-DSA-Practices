class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>>rows;

        for(auto x : reservedSeats){
            rows[x[0]].insert(x[1]);
        }

        int total = (n - rows.size()) * 2;

        for(auto [row, seats] : rows){
            bool left = true;
            bool right = true;
            bool middle = true;

            for(int s : {2, 3, 4, 5}){
                if(seats.count(s))
                    left = false;
            }

            for(int s : {4, 5, 6, 7}){
                if(seats.count(s))
                    middle = false;
            }

            for(int s : {6, 7, 8, 9}){
                if(seats.count(s))
                    right = false;
            }

            if(left && right){
                total += 2;
            }

            else if(left || middle || right){
                total += 1;
            }
        }

        return total;
    }
};
