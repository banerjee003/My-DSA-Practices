class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int>s;
        vector<int>result(n,0);
        int prev = 0;

        for(auto log : logs){
            int firstColon = log.find(':'); 
            int secondColon = log.find(':', firstColon + 1); 
            int id = stoi(log.substr(0, firstColon)); 
            string type = log.substr( firstColon + 1, secondColon - firstColon - 1 ); 
            int time = stoi(log.substr(secondColon + 1));

            if(type == "start"){
                if(!s.empty()){
                    result[s.top()] += time - prev;
                }
                s.push(id);
                prev = time;
            }
            else{
                result[s.top()] += time - prev + 1;
                s.pop();
                prev = time + 1;
            }
        }

        return result;
    }
};
