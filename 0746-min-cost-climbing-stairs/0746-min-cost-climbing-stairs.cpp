class Solution {
public:
    vector<int>dp;
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size());
        fill(dp.begin(), dp.end(), -1);
        return min(minCost(0, cost), minCost(1, cost));
    }

    
    int minCost(int i, vector<int>& cost){
        if(i>=cost.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int op1 = minCost(i+1, cost) + cost[i];
        int op2 = minCost(i+2, cost) + cost[i];
        return dp[i] = min(op1, op2);

    }
};