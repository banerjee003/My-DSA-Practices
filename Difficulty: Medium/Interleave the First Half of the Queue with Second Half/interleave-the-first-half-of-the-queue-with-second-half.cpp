class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int>first;
        
        int n = q.size();
        n /= 2;
        
        while(n--){
            first.push(q.front());
            q.pop();
        }
        
        while(!first.empty()){
            q.push(first.front());
            q.push(q.front());
            
            q.pop();
            first.pop();
        }
    }
};
