class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool positive = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            positive = false;
        }

        long new_dividend = abs((long)dividend);
        long new_divisor = abs((long)divisor);
        long result = 0;

        int power = 0;
        while (new_divisor <= (new_dividend >> 1)) {
            new_divisor = new_divisor << 1;
            power++;
        }
        
        while (power >= 0) {
            if (new_dividend >= new_divisor) {
                result += (1 << power);
                new_dividend -= new_divisor;
            }
            power--;
            new_divisor = new_divisor >> 1;
        }
        
        return positive ? result : -result;
    }
};