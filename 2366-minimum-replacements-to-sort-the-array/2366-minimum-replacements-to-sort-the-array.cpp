class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long n = nums.size();
        long long result = 0, counter;
        for(int i = n-2; i >= 0; i--){
            cout << "i: " << i << endl;
            if(nums[i] <= nums[i+1]) continue;
            else{
                if(nums[i] % nums[i+1] == 0){
                    counter = nums[i] / nums[i+1];
                    nums[i] = nums[i] / counter;
                }else{
                    counter = ceil((double)nums[i] / nums[i+1]);
                    nums[i] = nums[i] / counter;
                }
                result += counter - 1;
            }
            
        }
        return result;
    }
};