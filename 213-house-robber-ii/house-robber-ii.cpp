class Solution {
private: 
    long long int solve(vector<int>& arr){
        int n = arr.size();
        long long int prev = arr[0];
        long long int prev2 = 0;

        for(int i = 1; i < n; i++){
            long long int pick = arr[i];
            if(i > 1)
                pick += prev2;
            long long int nonPick = prev;

            long long int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }

public:
    long long int rob(vector<int> &arr) {
        int n = arr.size();
        if(n == 1)
            return arr[0];

        vector<int> arr1, arr2;
        for(int i = 0; i < n; i++){
            if(i != 0) arr1.push_back(arr[i]);
            if(i != n - 1) arr2.push_back(arr[i]);
        }

        return max(solve(arr1), solve(arr2));
    }
};
