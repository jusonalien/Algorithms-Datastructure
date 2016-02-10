class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num_bits = 0;
        if(n == 0)
            return num_bits;
        while(n) {
            if(n&1)
                ++num_bits;
            n >>= 1;
        }
        return num_bits;
    }
};
