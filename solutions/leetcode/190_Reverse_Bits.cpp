class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;


        // need to shift every number 32 times
        for (int i = 0; i < 32; i++){
            res <<= 1;
            res |= n & 1;
            n >>= 1;
        }

        return res;
    }
};