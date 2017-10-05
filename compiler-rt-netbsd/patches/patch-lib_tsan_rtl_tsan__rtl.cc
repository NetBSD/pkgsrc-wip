$NetBSD$

--- lib/tsan/rtl/tsan_rtl.cc.orig	2017-07-24 13:39:38.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl.cc
@@ -46,7 +46,9 @@ extern "C" void __tsan_resume() {
 namespace __tsan {
 
 #if !SANITIZER_GO && !SANITIZER_MAC
+#if !SANITIZER_NETBSD
 __attribute__((tls_model("initial-exec")))
+#endif
 THREADLOCAL char cur_thread_placeholder[sizeof(ThreadState)] ALIGNED(64);
 #endif
 static char ctx_placeholder[sizeof(Context)] ALIGNED(64);
