class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;

        int residual = 0;
        int shift = 0;
        while (a != 0 && b != 0){
            if ((a & 1) && (b & 1)){
                residual = 1;
                sum <<= 1;
            }
        }
    }
};