///
/// Random Array and Array Permutation
///

#ifndef cf_algo_arrayrandperm
#define cf_algo_arrayrandperm

#include "algo_mersennetwister.h"

#ifndef cf_chrono
    #define cf_chrono
    #include <chrono>
#endif

namespace algo {
    // Get array
    template<class big_obj> big_obj* GetArray(size_t nb, big_obj maxval) {
        return GetArray(nb, maxval, algo::RandomGenerator(std::chrono::system_clock::now().time_since_epoch().count()));
    }
    // Get array
    template<class big_obj> big_obj* GetArray(size_t nb, big_obj maxval, algo::RandomGenerator gen) {
        big_obj *res = (big_obj*)malloc(nb * sizeof(big_obj));
        for (size_t i = 0; i < nb; ++i) res[i] = gen.get() % maxval;
        return res;
    }
    // Shuffle array
    template<class big_obj> void PermuteArray(big_obj *arg, size_t sz) {
        algo::RandomGenerator gen = algo::RandomGenerator(std::chrono::system_clock::now().time_since_epoch().count());
        PermuteArray(arg, sz, gen);
    }
    // Shuffle array
    template<class big_obj> void PermuteArray(big_obj *arg, size_t sz, algo::RandomGenerator gen) {
        size_t pos;
        big_obj val;
        while (sz > 1) { pos = gen.get() % sz; val = arg[pos]; arg[pos] = arg[--sz]; arg[sz] = val; }
    }
}
#endif // cf_algo_arrayrandperm
