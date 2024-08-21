class Solution {
public:
    vector<vector<int>> dp;
    int f(string &s, int i, int j) {
        if(i > j) return 0;
        else if(dp[i][j] != -1) return dp[i][j];
        int ans = f(s, i, j - 1) + 1;

        for(int k = i; k < j; k++) {
            if(s[k] == s[j]) {
                ans = min(ans, f(s, i, k) + f(s, k + 1, j - 1));
            }
        }

        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
        int n = s.size();
        dp.resize(n + 1, vector<int>(n + 1, -1)); 
        return f(s, 0, n - 1); 
    }
};