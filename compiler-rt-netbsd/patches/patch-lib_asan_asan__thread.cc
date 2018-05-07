$NetBSD$

--- lib/asan/asan_thread.cc.orig	2018-02-01 23:46:05.000000000 +0000
+++ lib/asan/asan_thread.cc
@@ -300,8 +300,11 @@ void AsanThread::SetThreadStackAndTls(co
 
 void AsanThread::ClearShadowForThreadStackAndTLS() {
   PoisonShadow(stack_bottom_, stack_top_ - stack_bottom_, 0);
-  if (tls_begin_ != tls_end_)
-    PoisonShadow(tls_begin_, tls_end_ - tls_begin_, 0);
+  if (tls_begin_ != tls_end_) {
+    uptr tls_begin_aligned = RoundDownTo(tls_begin_, SHADOW_GRANULARITY);
+    uptr tls_end_aligned = RoundUpTo(tls_end_, SHADOW_GRANULARITY);
+    PoisonShadow(tls_begin_aligned, tls_end_aligned - tls_begin_aligned, 0);
+  }
 }
 
 bool AsanThread::GetStackFrameAccessByAddr(uptr addr,
