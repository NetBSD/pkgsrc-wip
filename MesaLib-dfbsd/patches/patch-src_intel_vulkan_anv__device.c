$NetBSD: patch-src_intel_vulkan_anv__device.c,v 1.1 2018/10/07 23:49:31 ryoon Exp $

* Without sysinfo() fall back to sysconf()
* Define ETIME if missing

FreeBSD Bugzilla - Bug 225415: graphics/mesa-dri: update to 18.0.0
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415

https://reviews.freebsd.org/D17872

* Define CLOCK_MONOTONIC_RAW if missing

--- src/intel/vulkan/anv_device.c.orig	2018-12-11 21:13:57.000000000 +0000
+++ src/intel/vulkan/anv_device.c
@@ -25,7 +25,9 @@
 #include <stdbool.h>
 #include <string.h>
 #include <sys/mman.h>
+#ifdef __GLIBC__
 #include <sys/sysinfo.h>
+#endif
 #include <unistd.h>
 #include <fcntl.h>
 #include <xf86drm.h>
@@ -44,6 +46,17 @@
 
 #include "genxml/gen7_pack.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+#ifndef CLOCK_MONOTONIC_RAW
+# ifdef CLOCK_MONOTONIC_FAST
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC_FAST
+# else
+#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+# endif
+#endif
+
 static void
 compiler_debug_log(void *data, const char *fmt, ...)
 { }
@@ -64,10 +77,18 @@ static VkResult
 anv_compute_heap_size(int fd, uint64_t gtt_size, uint64_t *heap_size)
 {
    /* Query the total ram from the system */
+#ifdef __GLIBC__
    struct sysinfo info;
    sysinfo(&info);
 
    uint64_t total_ram = (uint64_t)info.totalram * (uint64_t)info.mem_unit;
+#else
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+   uint64_t total_ram = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
+#else
+   uint64_t total_ram = sysctlbyname(SYSCTL_MEMSIZE, &mem, &size, nullptr, 0);
+#endif
+#endif
 
    /* We don't want to burn too much ram with the GPU.  If the user has 4GiB
     * or less, we use at most half.  If they have more than 4GiB, we use 3/4.
