class Solution {
  public:
    int lcm(int a, int b) {
        // code here
        int i = max(a,b);
        while(true){
            if(i % a == 0 and i % b == 0){
                return i;
            }
            i++;
        }
    }
};