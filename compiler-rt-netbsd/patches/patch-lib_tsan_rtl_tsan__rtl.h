$NetBSD$

--- lib/tsan/rtl/tsan_rtl.h.orig	2017-08-28 21:09:44.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl.h
@@ -457,7 +457,7 @@ struct ThreadState {
 };
 
 #if !SANITIZER_GO
-#if SANITIZER_MAC || SANITIZER_ANDROID
+#if SANITIZER_MAC || SANITIZER_ANDROID || SANITIZER_NETBSD
 ThreadState *cur_thread();
 void cur_thread_finalize();
 #else
