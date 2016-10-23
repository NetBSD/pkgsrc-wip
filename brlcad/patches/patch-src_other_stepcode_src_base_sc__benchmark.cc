$NetBSD$

Add NetBSD support.

--- src/other/stepcode/src/base/sc_benchmark.cc.orig	2016-08-09 06:47:32.000000000 +0000
+++ src/other/stepcode/src/base/sc_benchmark.cc
@@ -3,6 +3,12 @@
 #include "sc_benchmark.h"
 #include "sc_memmgr.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
+
 #ifdef __WIN32__
 #include <Windows.h>
 #include <psapi.h>
@@ -69,6 +75,18 @@ benchVals getMemAndTime( ) {
         vals.userMilliseconds = 0;
         vals.sysMilliseconds = 0;
     }
+#elif defined(__NetBSD__)
+    long page_size_kb = sysconf( _SC_PAGE_SIZE ) / 1024;
+
+    struct kinfo_proc2 kinfo = {};
+    int mib[6] = { CTL_KERN, KERN_PROC2, KERN_PROC_PID, getpid(), sizeof(struct kinfo_proc2), 1 };
+    size_t len = sizeof(kinfo);
+    if (sysctl(mib, __arraycount(mib), &kinfo, &len, NULL, 0) != 0) {
+        vals.physMemKB  = kinfo.p_vm_rssize * page_size_kb;
+        vals.virtMemKB  = (kinfo.p_vm_vsize - kinfo.p_vm_rssize) * page_size_kb;
+        vals.userMilliseconds = (long)kinfo.p_uutime_sec * 1000L + (long)kinfo.p_uutime_usec / 1000L;
+        vals.sysMilliseconds  = (long)kinfo.p_ustime_sec * 1000L + (long)kinfo.p_ustime_usec / 1000L;
+    }
 #else
 #warning Unknown platform!
 #endif // __linux__
@@ -142,4 +160,3 @@ std::string benchmark::str( const benchV
     ss << "kb; User CPU time: " << bv.userMilliseconds << "ms; System CPU time: " << bv.sysMilliseconds << "ms";
     return ss.str();
 }
-
