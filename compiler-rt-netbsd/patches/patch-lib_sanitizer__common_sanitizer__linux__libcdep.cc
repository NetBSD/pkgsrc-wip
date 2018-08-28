$NetBSD$

--- lib/sanitizer_common/sanitizer_linux_libcdep.cc.orig	2018-08-21 21:25:38.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cc
@@ -25,6 +25,7 @@
 #include "sanitizer_freebsd.h"
 #include "sanitizer_linux.h"
 #include "sanitizer_placement_new.h"
+#include "sanitizer_posix.h"
 #include "sanitizer_procmaps.h"
 
 #include <dlfcn.h>  // for dlsym()
@@ -652,10 +653,10 @@ u32 GetNumberOfCPUs() {
 #if SANITIZER_FREEBSD || SANITIZER_NETBSD || SANITIZER_OPENBSD
   u32 ncpu;
   int req[2];
-  size_t len = sizeof(ncpu);
+  uptr len = sizeof(ncpu);
   req[0] = CTL_HW;
   req[1] = HW_NCPU;
-  CHECK_EQ(sysctl(req, 2, &ncpu, &len, NULL, 0), 0);
+  CHECK_EQ(internal_sysctl(req, 2, &ncpu, &len, NULL, 0), 0);
   return ncpu;
 #elif SANITIZER_ANDROID && !defined(CPU_COUNT) && !defined(__aarch64__)
   // Fall back to /sys/devices/system/cpu on Android when cpu_set_t doesn't
