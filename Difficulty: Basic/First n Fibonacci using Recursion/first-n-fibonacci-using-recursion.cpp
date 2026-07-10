class Solution {
  public:
    // Function to return list containing first n fibonacci numbers.
    vector<int> fibonacciNumbers(int n) {
        // code here
        int a = 0, b = 1, c = 1;
        vector<int>ans;
        for(int i = 0; i < n; i++){
            ans.push_back(a);
            a = b;
            b = c;
            c = a+b;
        }
        return ans;
    }
};
