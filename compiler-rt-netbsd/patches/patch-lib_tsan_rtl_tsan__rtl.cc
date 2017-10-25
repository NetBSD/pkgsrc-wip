$NetBSD$

--- lib/tsan/rtl/tsan_rtl.cc.orig	2017-10-17 18:35:43.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl.cc
@@ -371,7 +371,7 @@ void Initialize(ThreadState *thr) {
   // On MIPS, TSan initialization is run before
   // __pthread_initialize_minimal_internal() is finished, so we can not spawn
   // new threads.
-#ifndef __mips__
+#if !defined(__mips__) && !SANITIZER_NETBSD
   StartBackgroundThread();
   SetSandboxingCallback(StopBackgroundThread);
 #endif
