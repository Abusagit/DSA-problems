class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        while (x!=0){
            
            int cur = x % 10;
            x /= 10;
            
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX && cur > 7)){
                return 0;
            }
            
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN && cur < -8)){
                return 0;
            }
            
            reversed = 10 * reversed + cur;
        }
        return reversed;
    }
};