$NetBSD: patch-base_debug_debugger__posix.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- base/debug/debugger_posix.cc.orig	2011-05-24 08:01:33.000000000 +0000
+++ base/debug/debugger_posix.cc
@@ -6,11 +6,18 @@
 #include "build/build_config.h"
 
 #include <errno.h>
+#if !defined(OS_NETBSD) && !defined(OS_DRAGONFLY)
 #include <execinfo.h>
+#endif
 #include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/stat.h>
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+#include <sys/param.h>
+#elif defined(OS_DRAGONFLY)
+#include <sys/kinfo.h>
+#endif
 #if !defined(OS_NACL)
 #include <sys/sysctl.h>
 #endif
@@ -50,7 +57,7 @@ bool SpawnDebuggerOnProcess(unsigned /* 
   return false;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_BSD)
 
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
@@ -71,11 +78,23 @@ bool BeingDebugged() {
     KERN_PROC,
     KERN_PROC_PID,
     getpid()
+#if defined(OS_OPENBSD) || defined(OS_NETBSD) || defined(OS_DRAGONFLY)
+#if defined(OS_NETBSD)
+    , sizeof(struct kinfo_proc2),
+#else
+    , sizeof(struct kinfo_proc),
+#endif
+    400 /* XXX */
+#endif
   };
 
   // Caution: struct kinfo_proc is marked __APPLE_API_UNSTABLE.  The source and
   // binary interfaces may change.
+#if defined(OS_NETBSD)
+  struct kinfo_proc2 info;
+#else
   struct kinfo_proc info;
+#endif
   size_t info_size = sizeof(info);
 
   int sysctl_result = sysctl(mib, arraysize(mib), &info, &info_size, NULL, 0);
@@ -88,7 +107,15 @@ bool BeingDebugged() {
 
   // This process is being debugged if the P_TRACED flag is set.
   is_set = true;
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
+  being_debugged = (info.p_flag & P_TRACED) != 0;
+#elif defined(OS_FREEBSD)
+  being_debugged = (info.ki_flag & P_TRACED) != 0;
+#elif defined(OS_DRAGONFLY)
+  being_debugged = (info.kp_flags & P_TRACED) != 0;
+#else
   being_debugged = (info.kp_proc.p_flag & P_TRACED) != 0;
+#endif
   return being_debugged;
 }
 
