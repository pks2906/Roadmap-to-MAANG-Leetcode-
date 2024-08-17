class Solution {
public:
    long long maxPoints(std::vector<std::vector<int>>& pointsMatrix) {
        
        using ll = long long;

       
        int n = pointsMatrix[0].size();

        
        std::vector<ll> prevRow(n);

   
        const ll inf = 1e18;

       
        for (auto& points : pointsMatrix) {
            
            std::vector<ll> currentRow(n);

            ll leftMax = -inf, rightMax = -inf;

            for (int j = 0; j < n; ++j) {
                leftMax = std::max(leftMax, prevRow[j] + j);
                currentRow[j] = std::max(currentRow[j], points[j] + leftMax - j);
            }

            for (int j = n - 1; j >= 0; --j) {
                rightMax = std::max(rightMax, prevRow[j] - j);
                currentRow[j] = std::max(currentRow[j], points[j] + rightMax + j);
            }

            prevRow = std::move(currentRow);
        }

        
        return *std::max_element(prevRow.begin(), prevRow.end());
    }
};
