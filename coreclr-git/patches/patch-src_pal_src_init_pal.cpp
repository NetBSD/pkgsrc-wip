$NetBSD$

--- src/pal/src/init/pal.cpp.orig	2016-04-08 23:29:23.000000000 +0000
+++ src/pal/src/init/pal.cpp
@@ -72,6 +72,13 @@ int CacheLineSize;
 #include <mach-o/dyld.h>
 #endif // __APPLE__
 
+#ifdef __NetBSD__
+#include <sys/cdefs.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <kvm.h>
+#endif
+
 using namespace CorUnix;
 
 //
@@ -706,6 +713,33 @@ PAL_IsDebuggerPresent()
         return ((info.kp_proc.p_flag & P_TRACED) != 0);
 
     return FALSE;
+#elif defined(__NetBSD__)
+    int traced = -1;
+    kvm_t *kd;
+    int cnt;
+
+    struct kinfo_proc *info;
+    size_t size = sizeof(info);
+
+    kd = kvm_open(NULL, NULL, NULL, KVM_NO_FILES, "kvm_open");
+    if (kd == NULL)
+        goto fin;
+
+    info = kvm_getprocs(kd, KERN_PROC_PID, getpid(), &cnt);
+    if (info == NULL)
+        goto fin2;
+
+    traced = info->kp_proc.p_slflag & PSL_TRACED; 
+    kvm_close(kd);
+
+    if (traced != 0)
+        return TRUE;
+    else
+        return FALSE;
+fin2:
+    kvm_close(kd);
+fin:
+    return FALSE;
 #else
     return FALSE;
 #endif
