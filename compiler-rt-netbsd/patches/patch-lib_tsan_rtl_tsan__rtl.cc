$NetBSD$

--- lib/tsan/rtl/tsan_rtl.cc.orig	2018-05-10 23:16:36.000000000 +0000
+++ lib/tsan/rtl/tsan_rtl.cc
@@ -354,6 +354,7 @@ void Initialize(ThreadState *thr) {
   ctx = new(ctx_placeholder) Context;
   const char *options = GetEnv(SANITIZER_GO ? "GORACE" : "TSAN_OPTIONS");
   CacheBinaryName();
+  CheckASLR();
   InitializeFlags(&ctx->flags, options);
   AvoidCVE_2016_2143();
   InitializePlatformEarly();
