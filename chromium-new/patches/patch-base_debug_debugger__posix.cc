$NetBSD$

--- base/debug/debugger_posix.cc.orig	2016-06-24 01:02:08.000000000 +0000
+++ base/debug/debugger_posix.cc
@@ -54,8 +54,48 @@
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
+#else
+#if defined(OS_MACOSX) || defined(OS_BSD)
 // Based on Apple's recommended method as described in
 // http://developer.apple.com/qa/qa2004/qa1361.html
 bool BeingDebugged() {
@@ -167,6 +207,7 @@ bool BeingDebugged() {
 }
 
 #endif
+#endif
 
 // We want to break into the debugger in Debug mode, and cause a crash dump in
 // Release mode. Breakpad behaves as follows:
