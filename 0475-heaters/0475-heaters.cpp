class Solution {
public:
    bool solve(vector<int>& houses, vector<int>& heaters, int radius){
        int j = 0;
        for(int i = 0; heaters.size()>i; i++){
            int left = heaters[i] - radius, right = heaters[i] + radius;
            while(j < houses.size() && left <= houses[j] && houses[j] <= right){
                ++j;
            }
        } 
        return j == houses.size();
        
    }
    int bs(vector<int>& houses, vector<int>& heaters){
        int l = 0, r = 1e9;
        int result = -1;
        while(l<=r){
            int m = l + (r-l) / 2;
            if(solve(houses, heaters, m)){
                r = m -1; 
                result = m;
            }else 
                l = m + 1;
        }
        return result;

    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        return bs(houses, heaters);
    }
};