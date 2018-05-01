$NetBSD$

* Without sysinfo() fall back to sysconf()
* Define ETIME if missing

FreeBSD Bugzilla - Bug 225415: graphics/mesa-dri: update to 18.0.0
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225415

--- src/intel/vulkan/anv_device.c.orig	2018-02-09 02:17:59.000000000 +0000
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
@@ -40,6 +42,10 @@
 
 #include "genxml/gen7_pack.h"
 
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
+
 static void
 compiler_debug_log(void *data, const char *fmt, ...)
 { }
@@ -75,10 +81,14 @@ anv_compute_heap_size(int fd, uint64_t *
    }
 
    /* Query the total ram from the system */
+#ifdef __GLIBC__
    struct sysinfo info;
    sysinfo(&info);
 
    uint64_t total_ram = (uint64_t)info.totalram * (uint64_t)info.mem_unit;
+#else
+   uint64_t total_ram = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE);
+#endif
 
    /* We don't want to burn too much ram with the GPU.  If the user has 4GiB
     * or less, we use at most half.  If they have more than 4GiB, we use 3/4.
