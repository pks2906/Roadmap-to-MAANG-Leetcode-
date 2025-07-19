class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1); // len[i] = length of result after processing s[0...i-1]
        len[0] = 0;

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (islower(c)) {
                if (len[i] >= 1e15) len[i+1] = 1e15;
                else len[i+1] = len[i] + 1;
            } else if (c == '*') {
                len[i+1] = max(0LL, len[i] - 1);
            } else if (c == '#') {
                if (len[i] >= 5e14) len[i+1] = 1e15;
                else len[i+1] = len[i] * 2;
            } else if (c == '%') {
                len[i+1] = len[i]; // length stays same
            }
        }

        if (k >= len[n]) return '.';

        // Step 2: Go back in reverse to deduce the k-th character
        // This is like recursively unraveling the operations
        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            if (islower(c)) {
                if (len[i+1] == len[i] + 1) {
                    if (k == len[i]) {
                        return c;
                    }
                }
                // else, current length didn't change, skip
            } else if (c == '*') {
                if (len[i] + 1 == len[i+1]) {
                    // character was removed, so we can't retrieve it
                    // nothing to do
                } else {
                    // coming from reduced length, no effect
                }
            } else if (c == '#') {
                if (k < len[i]) {
                } else {
                    // Second half of duplication came from first half
                    // map k to k - len[i]
                    k -= len[i];
                }
            } else if (c == '%') {
                k = len[i] - 1 - k; // reverse the index
            }
        }

    
        return '.';
    }
};
