class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n = tickets.size();
        if(n == 0) return 0;

        int time = 0;

        for(int i=0; i < n; i++)
            q.push(i);

        while(!q.empty()){
            int person = q.front();
            q.pop();
            time++;
            tickets[person]--;

            if(person == k and tickets[person] == 0)
                return time;
            
            if(tickets[person] > 0)
                q.push(person);
        }
        return -1;
    }
};
