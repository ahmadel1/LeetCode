class Solution {
public:
    bool checkPalindrome(string n){
        for(int i= 0, j = n.size()-1; i<=j; i++, j--){
            if(n[i] != n[j])
                return false;
        }
        return true;
    }

    bool toBase(int n, int base){
        string res = "";
        while(n>0){
            res = to_string(n%base) + res;
            n /= base;
             cout << res << endl;
        }
        return checkPalindrome(res);
    }
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i <= n-2; i++){
            if(!toBase(n, i))return false;
        }
        return true;
    }
};