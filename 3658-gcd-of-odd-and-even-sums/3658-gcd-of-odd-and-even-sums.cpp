class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = 0, evenSum = 0;
        n *= 2;
        while(n--){
            if(n % 2 == 0) evenSum += n;
            else oddSum += n;
        }

        int gcd = 1;
        for(int i = 2; i <= min(oddSum,evenSum); i++){
            if(oddSum % i == 0 and evenSum % i == 0){
                gcd = i;
            }
        }
        return gcd;
    }
};
