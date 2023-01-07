class Solution {
public:
    double myPow(double x, int n) {
        long exponent = abs(n);
        double result = 1.0;

        double current_value = x;

        // n = 0 is prevented implicitly

        // x ^ (2a) = (x ^ 2) ^ a
        // x ^ (2a + 1) = x * (x ^ 2) ^ a
        


        // at each i we compute result * pow(current_value, exponent)

        // if exponent is odd --> result * current_value and then compute pow(current_valut ^ 2, exponent / 2)
        // otherwise compute 1 * pow(current_value ^ 2, exponent / 2)
        for (long i = exponent; i > 0; i /= 2){
            if (i % 2){
                result *= current_value;
            }

            current_value *= current_value;
        }

        return (n < 0) ? 1 / result : result;

    }
};