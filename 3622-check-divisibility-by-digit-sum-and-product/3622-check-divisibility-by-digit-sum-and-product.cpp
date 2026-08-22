class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int temp = n;

        while(temp > 0){
            int rem = temp % 10;
            sum += rem;
            product *= rem;
            temp /= 10;
        }

        if(n % (sum + product) == 0)
            return true;
        
        return false;
    }
};
