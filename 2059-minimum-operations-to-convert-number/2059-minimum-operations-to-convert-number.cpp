class Solution {
public:
    bool validate(queue<int>& q, vector<int>& visited, int x, int goal){
        if(x == goal)
            return true;
        if(x >= 0 && x <= 1000 && !visited[x]){
            q.push(x);
            visited[x] = 1;
        }
        return false;
    }

    int bfs(vector<int>& nums, int start, int goal){
        queue<int>q;
        vector<int> visited(1001, 0);
        visited[start] = 1;
        q.push(start);
        for(int sz = 1, level = 0; !q.empty(); ++level, sz = q.size()){
            while(sz--){
                int x = q.front();
                q.pop();
                for (int i = 0; i < (int) nums.size(); i++)
					if (validate(q, visited, x + nums[i], goal) ||
						validate(q, visited, x - nums[i], goal) ||
						validate(q, visited, x ^ nums[i], goal))
						return level + 1;
                    
            }
        }
        return -1;
    }
    int minimumOperations(vector<int>& nums, int start, int goal) {
        return bfs(nums, start, goal);   
    }
};