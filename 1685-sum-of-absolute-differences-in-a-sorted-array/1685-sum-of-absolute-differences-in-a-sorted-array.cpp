class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>res(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++)
            prefix[i] = prefix[i-1] + nums[i];
        for(int i = 0; n>i; i++){
            res[i] += abs(nums[i]*(n-i-1) - (prefix[n-1] - prefix[i])) ;
            res[i] += abs(nums[i]*(i+1)  - prefix[i]);
        }
        return res;

    }
};