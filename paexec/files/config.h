#if defined(__NetBSD__) || defined(__FreeBSD__) || \
    defined(__OpenBSD__) || defined(__DragonFly__) || \
    defined(__APPLE__) || defined(__linux__)
#include "portabhacks.h"
#else
#include <unistd.h>
struct option {
   const char *name;
   int has_arg;
   int *flag;
   int val;
};

#define getopt_long(argc, argv, shrt_opts, long_opts, index) \
       (long_opts != NULL ? getopt(argc, argv, shrt_opts) : -1)
#endif
