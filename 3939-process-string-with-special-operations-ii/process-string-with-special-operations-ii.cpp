class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1); 
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
                len[i+1] = len[i]; 
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; --i) {
            char c = s[i];
            if (islower(c)) {
                if (len[i+1] == len[i] + 1) {
                    if (k == len[i]) {
                        return c;
                    }
                }
            } else if (c == '*') {
                if (len[i] + 1 == len[i+1]) {
                    
                } else {
                }
            } else if (c == '#') {
                if (k < len[i]) {
                } else {
                    k -= len[i];
                }
            } else if (c == '%') {
                k = len[i] - 1 - k; 
            }
        }

    
        return '.';
    }
};
