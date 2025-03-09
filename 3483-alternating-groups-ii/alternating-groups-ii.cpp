class Solution {
 public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    const int n = colors.size();
    int ans = 0;
    vector<int> extendedColors(colors.begin(), colors.end());
    extendedColors.insert(extendedColors.end(), colors.begin(), colors.end());

    int count = 1;
    for (int i = 1; i < extendedColors.size(); ++i) {
      if (extendedColors[i] != extendedColors[i - 1]) {
        count++;
      } else {
        count = 1;
      }
      if (count >= k && i < n + k - 1)
        ans++;
    }

    return ans;
  }
};