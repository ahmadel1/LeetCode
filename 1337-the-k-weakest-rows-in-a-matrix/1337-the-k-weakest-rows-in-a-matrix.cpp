class Solution {
public:
    int bs(vector<int>& row){
        int l = 0, r = row.size()-1;
        while(l<=r){
            int m = l + (r - l) / 2;
            if(row[m])
                l = m + 1;
            else
                r = m - 1; 
        }
        return l;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<pair<int, int>>pq;
        for(int i = 0; n>i; i++){
            pq.push_back({bs(mat[i]),i});
        }
        sort(pq.begin(), pq.end());
        vector<int> result (k);
        for(int i = 0; k>i; i++)
            result[i] = pq[i].second;
        return result;
    }
};