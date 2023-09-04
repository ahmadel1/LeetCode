class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res;
        vector<int>::iterator lower = lower_bound(nums.begin(), nums.end(), target);
        vector<int>::iterator upper = upper_bound(nums.begin(), nums.end(), target);
        if(lower != nums.end()){
            if(*lower == target){
                res.push_back(lower-nums.begin());
                res.push_back(upper-nums.begin()-1);
                return res;
            }
        }
        return {-1, -1};
    }
};