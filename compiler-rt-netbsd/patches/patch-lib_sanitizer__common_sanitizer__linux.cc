$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.cc.orig	2018-06-01 09:47:10.441087020 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -1955,6 +1955,30 @@ void MaybeReexec() {
   // No need to re-exec on Linux.
 }
 
+void CheckASLR() {
+#if SANITIZER_NETBSD
+  int mib[3];
+  int paxflags;
+  size_t len = sizeof(int);
+
+  mib[0] = CTL_PROC;
+  mib[1] = internal_getpid();
+  mib[2] = PROC_PID_PAXFLAGS;
+
+  if (UNLIKELY(sysctl(mib, 3, &paxflags, &len, NULL, 0) == -1)) {
+    Printf("sysctl failed\n");
+    Die();
+  }
+
+  if (UNLIKELY(paxflags & CTL_PROC_PAXFLAGS_ASLR)) {
+    Printf("This sanitizer is not compatible with enabled ASLR\n");
+    Die();
+  }
+#else
+  // Do nothing
+#endif
+}
+
 void PrintModuleMap() { }
 
 void CheckNoDeepBind(const char *filename, int flag) {
