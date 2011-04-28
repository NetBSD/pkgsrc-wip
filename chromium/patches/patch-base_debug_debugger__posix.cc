$NetBSD: patch-base_debug_debugger__posix.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- base/debug/debugger_posix.cc.orig	2011-04-13 08:01:34.000000000 +0000
+++ base/debug/debugger_posix.cc
@@ -6,11 +6,16 @@
 #include "build/build_config.h"
 
 #include <errno.h>
+#if !defined(OS_NETBSD)
 #include <execinfo.h>
+#endif
 #include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/stat.h>
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+#include <sys/param.h>
+#endif
 #if !defined(OS_NACL)
 #include <sys/sysctl.h>
 #endif
@@ -50,7 +55,7 @@ bool SpawnDebuggerOnProcess(unsigned /* 
   return false;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_NETBSD)
 
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
@@ -71,11 +76,23 @@ bool BeingDebugged() {
     KERN_PROC,
     KERN_PROC_PID,
     getpid()
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+#if defined(OS_OPENBSD)
+    , sizeof(struct kinfo_proc),
+#else
+    , sizeof(struct kinfo_proc2),
+#endif
+    400 /* XXX */
+#endif
   };
 
   // Caution: struct kinfo_proc is marked __APPLE_API_UNSTABLE.  The source and
   // binary interfaces may change.
+#if defined(OS_MACOSX) || defined(OS_OPENBSD)
   struct kinfo_proc info;
+#else
+  struct kinfo_proc2 info;
+#endif
   size_t info_size = sizeof(info);
 
   int sysctl_result = sysctl(mib, arraysize(mib), &info, &info_size, NULL, 0);
@@ -88,7 +105,11 @@ bool BeingDebugged() {
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+  being_debugged = (info.p_flag & P_TRACED) != 0;
+#else
   being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
+#endif
   return being_debugged;
 }
 
