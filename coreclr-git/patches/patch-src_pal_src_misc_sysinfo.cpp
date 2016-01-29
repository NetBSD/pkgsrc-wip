$NetBSD$

--- src/pal/src/misc/sysinfo.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/misc/sysinfo.cpp
@@ -36,6 +36,7 @@ Revision History:
 #if HAVE_SYS_VMPARAM_H
 #include <sys/vmparam.h>
 #endif  // HAVE_SYS_VMPARAM_H
+#include <machine/vmparam.h>
 
 #if HAVE_MACH_VM_TYPES_H
 #include <mach/vm_types.h>
@@ -130,7 +131,7 @@ GetSystemInfo(
     lpSystemInfo->dwActiveProcessorMask_PAL_Undefined = 0;
 
 #if HAVE_SYSCONF
-#if defined(__hppa__) || ( defined (_IA64_) && defined (_HPUX_) )
+#if ( (defined(__hppa__) || defined (_IA64_)) && defined (_HPUX_) )
     struct pst_dynamic psd;
     if (pstat_getdynamic(&psd, sizeof(psd), (size_t)1, 0) != -1) {
         nrcpus = psd.psd_proc_cnt;
@@ -139,7 +140,7 @@ GetSystemInfo(
         ASSERT("pstat_getdynamic failed (%d)\n", errno);
     }
 
-#else // !__hppa__
+#else // !_HPUX_
     nrcpus = sysconf(_SC_NPROCESSORS_ONLN);
     if (nrcpus < 1)
     {
@@ -351,4 +352,3 @@ PAL_GetLogicalProcessorCacheSizeFromOS()
 
     return cacheSize;
 }
-
