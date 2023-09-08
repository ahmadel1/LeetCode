class Solution {
public:
    bool getSum(vector<int>& nums, int n, int threshold){
        long long sum = 0;
        vector<int>tmp(nums.size(), 0);
        for(int i = 0; nums.size()>i; i++){
            tmp[i] = ceil((float)nums[i] / n);
            sum += tmp[i];
        }
        return sum <= threshold;
    }
    int bs(vector<int>& nums, int target){
        int l = 1, r = 1000000;
        int res = 1;
        while(l<=r){
            int m = l + (r-l) / 2;
            if(getSum(nums, m, target)){
                r = m - 1;
                res = m;
            }else
                l = m + 1;
        }
        return res;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        return bs(nums, threshold);
    }
};