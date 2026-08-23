class Solution {
public:
    bool sumGame(string num) {
        int leftQ = 0, rightQ = 0, leftSum = 0, rightSum = 0;
        int n = num.size();

        for(int i = 0; i < n/2; i++){
            if(num[i] == '?'){
                leftQ++;
            }
            else{
                leftSum += (num[i] - '0');
            }
        }

        for(int i = n/2; i < n; i++){
            if(num[i] == '?'){
                rightQ++;
            }
            else{
                rightSum += (num[i] - '0');
            }
        }


        if(leftQ == rightQ){
            if(leftSum == rightSum){
                return false;
            }
        }

        else{
            int diff = leftSum - rightSum;
            if(2 * diff == 9 * (rightQ - leftQ)){
                return false;
            }
        }
        return true;
    }
};
