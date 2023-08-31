class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        
        int mx_value = INT_MIN;
        for(int i = 0; arr.size()>i; i++){
            mx_value = max(mx_value, arr[i]);
        }
        mx_value += 50000;
        vector<int>freq(mx_value + 1, 0);
        for(int i = 0; arr.size()>i; i++){
            freq[arr[i]+50000]++;
        }
        
        int idx = 0;
        for(int i = 0; i<=mx_value; i++){
            for(int j = 0; j < freq[i]; j++, idx++){
                cout << arr[idx] << endl;
                arr[idx] = i - 50000;
            }
        }
        return arr;
    }
};