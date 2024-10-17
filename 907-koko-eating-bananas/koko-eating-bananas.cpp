#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum element in the array
int findMax(vector<int> &piles) {
    int maxi = INT_MIN;
    int n = piles.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, piles[i]);
    }
    return maxi;
}

// Function to calculate the total number of hours required with a given hourly rate
long long calculateTotalHours(vector<int> &piles, int hourly) {
    long long totalH = 0;  // Use long long to avoid overflow
    int n = piles.size();
    for (int i = 0; i < n; i++) {
        // Calculate hours needed for each pile using integer arithmetic
        totalH += (piles[i] + hourly - 1) / hourly;
    }
    return totalH;
}

// Solution class with the function to determine the minimum eating speed
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;  // Try to find a smaller rate
            } else {
                low = mid + 1;  // Increase the rate
            }
        }
        return low;
    }
};

