class Solution {
public:
    bool solve(vector<int>& bloomDay, int m, int k, int subtractor){
        int kcounter = 0, mcounter = 0;
        for(int i = 0; bloomDay.size()>i; i++){
            if((bloomDay[i] - subtractor) <= 0) kcounter++;
            else kcounter = 0;
            if(kcounter == k){
                mcounter++;
                kcounter = 0;
            }
        }
        return mcounter >= m;
    }
    int bs(vector<int>& bloomDay, int m, int k){
        int l = 1, r = 1000000000;
        int result = 0;
        while(l<=r){
            int mid = l + (r-l) / 2;
            if(solve(bloomDay, m, k, mid)){
                r = mid - 1;
                result = mid;
            }else
                l = mid + 1;
        }
        return result;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m*k) return -1;
        return bs(bloomDay, m, k);
    }
};