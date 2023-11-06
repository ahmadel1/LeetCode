class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        sort(numbers.begin(), numbers.end());
        for(int i = 0; numbers.size()>i; i++){
            int l = i, r = numbers.size() -1, m;
            while(l <= r){
                m = (l + r)/ 2;
                int res = numbers[i] + numbers[m];
                if(res == target && m != i)
                    return vector<int>{i+1, m+1};
                else if (res > target)
                    r = m - 1;
                else 
                    l = m + 1;
            }
        }
        return vector<int>{1,1};
    }   
};