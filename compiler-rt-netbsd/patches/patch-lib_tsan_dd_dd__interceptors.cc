$NetBSD$

--- lib/tsan/dd/dd_interceptors.cc.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/tsan/dd/dd_interceptors.cc
@@ -15,9 +15,13 @@
 
 using namespace __dsan;
 
+#if SANITIZER_NETBSD
 __attribute__((tls_model("initial-exec")))
+#endif
 static __thread Thread *thr;
+#if SANITIZER_NETBSD
 __attribute__((tls_model("initial-exec")))
+#endif
 static __thread volatile int initing;
 static bool inited;
 static uptr g_data_start;
