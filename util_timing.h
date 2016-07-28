///
/// Timing
///

#ifndef cf_util_timing
#define cf_util_timing

#ifdef __SYSWIN
#ifndef cf_windows
    #define cf_windows
    #include <Windows.h>
#endif

using namespace std;

namespace util {
    uint64_t get_cpu_time(uint64_t div = 10000) {
        FILETIME a, b, c, d;
        if (!GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d)) return 0;
        //return (uint64_t)c.dwLowDateTime + (uint64_t)d.dwLowDateTime + ((uint64_t)c.dwHighDateTime << 32) + ((uint64_t)d.dwHighDateTime << 32);
        return ((uint64_t)d.dwLowDateTime + ((uint64_t)d.dwHighDateTime << 32)) / div;
    }
}
#else

#ifndef cf_time
    #define cf_time
    #include <time.h>
#endif

using namespace std;

namespace util {
    uint64_t get_cpu_time(uint64_t div = 10000) { return (uint64_t)(clock() / div); }
}
#endif

#endif // cf_util_timing
