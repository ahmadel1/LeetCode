class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int>Nprev(n+1, 0);
        vector<int>Yprev(n+1, 0);
        for(int i = 0; n>i; i++){
            if(customers[i] == 'Y') Yprev[i] = 1;
            if(customers[i] == 'N') Nprev[i+1] = 1;
        }

        for(int i = n-1; i>=0; i--) Yprev[i] += Yprev[i+1];
        for(int i = 1; i<n+1; i++) Nprev[i] += Nprev[i-1];

        int result = 0, mn=INT_MAX;
        for(int i = 0; n+1>i; i++){
            if(Yprev[i] + Nprev[i]  < mn){
                mn = Yprev[i] + Nprev[i];
                result = i;
            }
        }
        return result;
    }
};