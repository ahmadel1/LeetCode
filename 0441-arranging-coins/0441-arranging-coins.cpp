class Solution {
public:
    bool validate(int n, long long level){
        long long sum = (level * (level +1 )) / 2;
        return sum <= n;
    }
    int bs(int n){
        int l = 0,  r = n, result = 0;
        while(l<=r){
            int m = l +(r-l) / 2;
            if(validate(n, m)) l = m + 1, result = m;
            else r = m - 1;
        }
        return result;
    }
    int arrangeCoins(int n) {
        return bs(n);
    }
};