///
/// Find a local minimum in a n x n grid - O(n)
///

#ifndef cf_utest_gridlocalmin
#define cf_utest_gridlocalmin

#ifndef cf_stdlib
    #define cf_stdlib
    #include <stdlib.h>
#endif
#ifndef cf_cstdint
    #define cf_cstdint
    #include <cstdint>
#endif

#ifndef cf_iostream
    #define cf_iostream
    #include <iostream>
#endif
#ifndef cf_string
    #define cf_string
    #include <string>
#endif

#include "algo_arrayrandperm.h"
#include "algo_gridlocalmin.h"

#include "util_timing.h"

using namespace std;
using namespace algo;
using namespace util;

namespace unittest {
    void AffGrid(uint32_t *data, size_t nb) {
        for (uint32_t i = 0; i < (nb * nb); ++i) {
            cout << data[i] << " ";
            if ((i + 1) % nb == 0) cout << endl;
        }
        cout << "==================================" << endl;
    }
    void GridLocalMin_CheckSolution(uint32_t *data, size_t nb, size_t pos) {
        if (((pos + 1) % nb) > 0 && data[pos + 1] < data[pos]) cout << "Error East." << endl;
        if ((pos % nb) > 0 && data[pos - 1] < data[pos]) cout << "Error West." << endl;
        if (pos >= nb && data[pos - nb] < data[pos]) cout << "Error North." << endl;
        if ((pos + nb) < (nb * nb) && data[pos + nb] < data[pos]) cout << "Error South." << endl;
    }
    void GridLocalMin() {
        cout << "UnitTest -> 2D Grid Local Minimum" << endl;
        uint64_t cpu_time;
        uint32_t i, j, nb = 3000, maxloop = 100, pos; // 52 296 728 1328
        uint32_t tot = nb * nb;
        uint32_t *data = (uint32_t*)malloc(tot * sizeof(uint32_t));
        for (i = 0; i < tot; ++i) data[i] = i;
        string _na = "GridLocalMin Lines ";
        cpu_time = get_cpu_time();
        for(j = 0; j < maxloop; ++j) {
            PermuteArray(data, tot);
            pos = algo::GridLocalMinLines(data, nb, 0, tot - 1);
            GridLocalMin_CheckSolution(data, nb, pos);
        }
        cpu_time = get_cpu_time() - cpu_time;
        cout << _na << cpu_time << endl;
        _na = "GridLocalMin Lines-3 ";
        cpu_time = get_cpu_time();
        for(j = 0; j < maxloop; ++j) {
            PermuteArray(data, tot);
            pos = algo::GridLocalMinLines3(data, nb, 0, tot - 1);
            GridLocalMin_CheckSolution(data, nb, pos);
        }
        cpu_time = get_cpu_time() - cpu_time;
        cout << _na << cpu_time << endl;
        _na = "GridLocalMin ";
        cpu_time = get_cpu_time();
        for(j = 0; j < maxloop; ++j) {
            PermuteArray(data, tot);
            pos = algo::GridLocalMin(data, nb, tot, 0, tot - 1);
            GridLocalMin_CheckSolution(data, nb, pos);
        }
        cpu_time = get_cpu_time() - cpu_time;
        cout << _na << cpu_time << endl;
    }
}
#endif // cf_utest_gridlocalmin
