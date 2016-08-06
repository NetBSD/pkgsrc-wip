$NetBSD$

--- base/debug/debugger_posix.cc.orig	2016-08-05 17:13:37.000000000 +0000
+++ base/debug/debugger_posix.cc
@@ -54,7 +54,47 @@
 namespace base {
 namespace debug {
 
-#if defined(OS_MACOSX) || defined(OS_BSD)
+#if defined(OS_NETBSD)
+bool BeingDebugged() {
+  static bool is_set = false;
+  static bool being_debugged = false;
+  int ret;
+
+  if (is_set)
+    return being_debugged;
+
+  int mib[6];
+  size_t size;
+  struct kinfo_proc2 kproc;
+
+  mib[0] = CTL_KERN;
+  mib[1] = KERN_PROC2;
+  mib[2] = KERN_PROC_PID;
+  mib[3] = getpid();
+  mib[4] = sizeof(kinfo_proc2);
+  mib[5] = 1;
+
+  ret = sysctl((int *)mib, 6, NULL, &size, NULL, 0);
+  if (ret == -1) {
+    return -1;
+  }
+
+  mib[5] = (size / sizeof(kinfo_proc2));
+
+  ret = sysctl((int *)mib, 6, &kproc, &size, NULL, 0);
+  if (ret == -1) {
+    return -1;
+    is_set = true;
+    being_debugged = false;
+    return being_debugged;
+  }
+
+  is_set = true;
+  being_debugged = (kproc.p_flag & P_TRACED) != 0;
+  return being_debugged;
+
+}
+#elif defined(OS_MACOSX) || defined(OS_BSD)
 
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
@@ -90,7 +130,11 @@ bool BeingDebugged() {
 
   // Caution: struct kinfo_proc is marked __APPLE_API_UNSTABLE.  The source and
   // binary interfaces may change.
+#if defined(OS_NETBSD)
+  struct kinfo_proc2 info;
+#else
   struct kinfo_proc info;
+#endif
   size_t info_size = sizeof(info);
 
 #if defined(OS_OPENBSD)
