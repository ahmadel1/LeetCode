class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>horz;
        for(auto point: points)
            horz.push_back(point[0]);
        sort(horz.begin(), horz.end());
        int result = 0;
        for(int i = 1; i<horz.size(); i++)
            result = max(result, horz[i] - horz[i-1]);
        return result;
    }
};