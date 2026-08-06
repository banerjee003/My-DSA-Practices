class Solution {
public:
    int digitProd(int n){
        int product = 1;
        while(n > 0){
            int rem = n % 10;
            product *= rem;
            n /= 10;
        }
        return product;
    }

    int smallestNumber(int n, int t) {
        
        while(true){
            int product = digitProd(n);
            if(product % t == 0){
                
                break;
            }
            n++;
        }
        return n;
    }
};
