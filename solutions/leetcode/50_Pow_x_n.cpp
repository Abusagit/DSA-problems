class Solution {
public:
    double myPow(double x, int n) {
        long exponent = abs(n);
        double result = 1.0;

        double current_value = x;

        // n = 0 is prevented implicitly

        // x ^ (2a) = (x ^ 2) ^ a
        for (long i = exponent; i > 0; i /= 2){
            if (i % 2){
                result *= current_value;
            }

            current_value *= current_value;
        }

        return (n < 0) ? 1 / result : result;

    }
};