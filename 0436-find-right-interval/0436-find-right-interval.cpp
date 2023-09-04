class Solution {
public:
    int binary_search(vector<vector<int>>& intervals, int target){
        int l = 0, r = intervals.size() - 1;  
        while(l<=r){
            int m = l + (r -l) / 2;
            if(intervals[m][0] == target)
                return m;
            if(intervals[m][0] < target)
                l =  m + 1;
            else if(intervals[m][0] > target)
                r = m - 1;            
        } 
        return l;
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>, int>indexing;
        vector<int>result(intervals.size(), -1);

        for(int i = 0; intervals.size()>i; i++)
            indexing[intervals[i]] = i;
        sort(intervals.begin(), intervals.end());

        
        for(auto i :intervals){
            int x = binary_search(intervals, i[1]);
            if(x>intervals.size()-1) x = -1;
            if (x != -1){
                result[indexing[i]] = indexing[intervals[x]];
            }
        }
        
        return result;
    }
};