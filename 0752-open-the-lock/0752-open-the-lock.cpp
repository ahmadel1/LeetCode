class Solution {
public:
    string next(int i, string curr){
        if(curr[i] == '9')
            curr[i] = '0';
        else 
            curr[i] = curr[i] + 1;     
        return curr;
    }
    string prev(int i, string curr){
        if(curr[i] == '0')
            curr[i] = '9';
        else 
            curr[i] = curr[i] - 1;     
        return curr;
    }

    int bfs(vector<string>& deadends, string target){
        string start= "0000";
        unordered_set<string> visited { deadends.begin(), deadends.end()};
        if(!visited.insert("0000").second)return -1;
        queue<string>q;
        q.push(start);
        for(int sz = 1, level = 0; !q.empty(); level++, sz = q.size()){
            while(sz--){
                string curr  = q.front();
                q.pop();
                for(int i = 0; 4>i; i++){
                    string nxt = next(i, curr);
                    if(nxt == target)
                        return level + 1;
                    if(visited.insert(nxt).second)
                        q.push(nxt);
                
                    string prv = prev(i, curr);
                    if(prv == target)
                        return level+1;
                    if(visited.insert(prv).second)
                        q.push(prv);
                }
            }
        }
        return -1;
    }
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000")return 0;
        return bfs(deadends, target);

    }
};