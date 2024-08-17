class Solution {
public:
    long long maxPoints(std::vector<std::vector<int>>& pointsMatrix) {
        // Alias for long long type to be used later in the function
        using ll = long long;

        // Number of columns in the input matrix
        int n = pointsMatrix[0].size();

        // Initial row (f) will hold the maximum points for each column
        std::vector<ll> prevRow(n);

        // Representing infinity as a large number, useful to ensure
        // that if a path includes an unfeasible option, it is ignored
        const ll inf = 1e18;

        // Loop over each row in the points matrix
        for (auto& points : pointsMatrix) {
            // Temporary row (g) to calculate new scores considering the transition
            std::vector<ll> currentRow(n);

            // Variables to track the left and right maximum of previous row
            ll leftMax = -inf, rightMax = -inf;

            // Forward iteration: calculate max points from the left to the current position
            for (int j = 0; j < n; ++j) {
                leftMax = std::max(leftMax, prevRow[j] + j);
                currentRow[j] = std::max(currentRow[j], points[j] + leftMax - j);
            }

            // Backward iteration: calculate max points from the right to the current position
            for (int j = n - 1; j >= 0; --j) {
                rightMax = std::max(rightMax, prevRow[j] - j);
                currentRow[j] = std::max(currentRow[j], points[j] + rightMax + j);
            }

            // Update the previous row to the current row for next iteration
            prevRow = std::move(currentRow);
        }

        
        return *std::max_element(prevRow.begin(), prevRow.end());
    }
};
