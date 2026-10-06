class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        if(boxTypes.empty()) return 0;

        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1] > b[1];
        });
        
        int total = 0;
        for(int i = 0; i < n; i++){
            if(truckSize > 0){
                int numberOfBoxes = boxTypes[i][0];
                int numberOfUnitsPerBox = boxTypes[i][1];

                if(truckSize >= numberOfBoxes){
                    total += (numberOfBoxes * numberOfUnitsPerBox);
                    truckSize -= numberOfBoxes;
                }
                else{
                    total += (truckSize * numberOfUnitsPerBox);
                    truckSize = 0;
                    break;
                }
            }
        }
        return total;
    }
};
