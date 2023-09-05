class Solution {
public:
    int find_sides(vector<int>&nums, int l, int target){
            int r = nums.size() - 1;
            int result = nums.size();
            while(l <= r){
                int m = l + (r-l) / 2;
                if(target > nums[m]) l = m + 1;
                else r = m - 1, result = m;
            }
            return result;
    }
    int triangleNumber(vector<int>& nums) {
        int counter = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; n-2>i; i++){
            for(int k = i+1; n-1 > k && nums[i]!=0; k++){
                int x = find_sides(nums, k + 1, nums[i] + nums[k]);
                counter += x - k - 1;
            }
        }
        return counter;
    }
};