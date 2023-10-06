class Solution {
public:
    int integerBreak(int n) {
        int result = INT_MIN;
        for(int i = 2; i<=n; i++){
            vector<int>nums(i, 0);
            int tmp = n;
            int j = 0;
            while(tmp--){
                nums[j]++;
                j++;
                if(j == i)j = 0;
            }
            int product = 1;
            for(auto i : nums)
                product *= i;
            result = max(result, product);
        }
        return result;
        
    }
};