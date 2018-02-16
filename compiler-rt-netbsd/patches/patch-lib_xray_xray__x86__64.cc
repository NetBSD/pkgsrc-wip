$NetBSD$

--- lib/xray/xray_x86_64.cc.orig	2018-02-15 16:00:57.000000000 +0000
+++ lib/xray/xray_x86_64.cc
@@ -3,7 +3,8 @@
 #include "xray_defs.h"
 #include "xray_interface_internal.h"
 
-#if SANITIZER_FREEBSD
+#if SANITIZER_FREEBSD || SANITIZER_NETBSD
+#include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
 
@@ -76,7 +77,7 @@ uint64_t getTSCFrequency() XRAY_NEVER_IN
   }
   return TSCFrequency == -1 ? 0 : static_cast<uint64_t>(TSCFrequency);
 }
-#elif SANITIZER_FREEBSD
+#elif SANITIZER_FREEBSD || SANITIZER_NETBSD
 uint64_t getTSCFrequency() XRAY_NEVER_INSTRUMENT {
     long long TSCFrequency = -1;
     size_t tscfreqsz = sizeof(TSCFrequency);
