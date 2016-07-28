///
/// Mersenne Twister Pseudo Random Number Generator
///

#ifndef cf_algo_mersennetwister
#define cf_algo_mersennetwister

#define mertwi_length 624
#define mertwi_bitmask32 0xffffffff
#define mertwi_bitpow31 0x80000000

namespace algo {
    // Mersenne twister pseudo-random number generator
    class RandomGenerator {
        size_t *mt, idx;
        void gen() {
            size_t i, y;
            for(i = 0; i < mertwi_length; ++i) {
                y = (mt[i] & mertwi_bitpow31) + (mt[(i + 1) % mertwi_length] & (mertwi_bitpow31 - 1));
                mt[i] = mt[(i + 397) % mertwi_length] ^ (y >> 1);
                if (y & 1) mt[i] ^= 0x9908B0DF;
            }
        }
        public:
        RandomGenerator(size_t seed) {
            mt = (size_t*)malloc(mertwi_length * sizeof(size_t)); mt[0] = seed; idx = 0;
            for (size_t i = 1; i < mertwi_length; ++i) mt[i] = (0x6C078965 * (mt[i - 1] ^ (mt[i - 1] >> 30)) + i) & mertwi_bitmask32;
        }
        ~RandomGenerator() { free(mt); }
        size_t get() {
            if (idx == 0) gen();
            size_t y = mt[idx];
            y ^= y >> 11; y ^= (y << 7) & 0x9D2C5680; y ^= (y << 15) & 0xEFC60000; y ^= y >> 18; idx = (idx + 1) % mertwi_length;
            return y;
        }
    };
}
#endif // cf_algo_mersennetwister
