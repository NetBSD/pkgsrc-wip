$NetBSD$

--- lib/xray/xray_x86_64.cc.orig	2018-08-31 08:13:42.000000000 +0000
+++ lib/xray/xray_x86_64.cc
@@ -1,5 +1,6 @@
 #include "cpuid.h"
 #include "sanitizer_common/sanitizer_common.h"
+#include "sanitizer_common/sanitizer_posix.h"
 #include "xray_defs.h"
 #include "xray_interface_internal.h"
 
@@ -87,13 +88,13 @@ uint64_t getTSCFrequency() XRAY_NEVER_IN
     size_t tscfreqsz = sizeof(TSCFrequency);
 #if SANITIZER_OPENBSD
     int Mib[2] = { CTL_MACHDEP, CPU_TSCFREQ };
-    if (sysctl(Mib, 2, &TSCFrequency, &tscfreqsz, NULL, 0) != -1) {
+    if (internal_sysctl(Mib, 2, &TSCFrequency, &tscfreqsz, NULL, 0) != -1) {
 #elif SANITIZER_MAC
-    if (sysctlbyname("machdep.tsc.frequency", &TSCFrequency, &tscfreqsz,
+    if (internal_sysctlbyname("machdep.tsc.frequency", &TSCFrequency, &tscfreqsz,
         NULL, 0) != -1 ) {
 
 #else
-    if (sysctlbyname("machdep.tsc_freq", &TSCFrequency, &tscfreqsz,
+    if (internal_sysctlbyname("machdep.tsc_freq", &TSCFrequency, &tscfreqsz,
         NULL, 0) != -1) {
 #endif
         return static_cast<uint64_t>(TSCFrequency);
