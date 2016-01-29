$NetBSD$

--- src/pal/src/misc/sysinfo.cpp.orig	2016-01-29 08:46:10.000000000 +0000
+++ src/pal/src/misc/sysinfo.cpp
@@ -37,6 +37,7 @@ Revision History:
 #if HAVE_SYS_VMPARAM_H
 #include <sys/vmparam.h>
 #endif  // HAVE_SYS_VMPARAM_H
+#include <machine/vmparam.h>
 
 #if HAVE_MACH_VM_TYPES_H
 #include <mach/vm_types.h>
@@ -144,7 +145,7 @@ GetSystemInfo(
         ASSERT("pstat_getdynamic failed (%d)\n", errno);
     }
 
-#else // !__hppa__
+#else // !_HPUX_
     nrcpus = sysconf(_SC_NPROCESSORS_ONLN);
     if (nrcpus < 1)
     {
