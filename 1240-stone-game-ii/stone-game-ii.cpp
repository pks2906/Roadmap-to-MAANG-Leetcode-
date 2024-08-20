class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    const int n = piles.size();
    vector<int> suffix(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    
    for (int i = n - 1; i >= 0; --i)
      suffix[i] = suffix[i + 1] + piles[i];

    
    for (int i = n - 1; i >= 0; --i) {
      for (int M = 1; M <= n; ++M) {
        for (int X = 1; X <= 2 * M && i + X <= n; ++X) {
          dp[i][M] = max(dp[i][M], suffix[i] - dp[i + X][max(M, X)]);
        }
      }
    }
    
    return dp[0][1];
  }
};
