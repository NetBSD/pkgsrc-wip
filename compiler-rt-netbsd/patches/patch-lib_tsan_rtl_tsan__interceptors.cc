$NetBSD$

--- lib/tsan/rtl/tsan_interceptors.cc.orig	2018-06-06 19:08:28.000000000 +0000
+++ lib/tsan/rtl/tsan_interceptors.cc
@@ -1736,12 +1736,6 @@ TSAN_INTERCEPTOR(void, abort, int fake) 
   REAL(abort)(fake);
 }
 
-TSAN_INTERCEPTOR(int, puts, const char *s) {
-  SCOPED_TSAN_INTERCEPTOR(puts, s);
-  MemoryAccessRange(thr, pc, (uptr)s, internal_strlen(s), false);
-  return REAL(puts)(s);
-}
-
 TSAN_INTERCEPTOR(int, rmdir, char *path) {
   SCOPED_TSAN_INTERCEPTOR(rmdir, path);
   Release(thr, pc, Dir2addr(path));
@@ -2709,7 +2703,6 @@ void InitializeInterceptors() {
   TSAN_INTERCEPT(fread);
   TSAN_INTERCEPT(fwrite);
   TSAN_INTERCEPT(abort);
-  TSAN_INTERCEPT(puts);
   TSAN_INTERCEPT(rmdir);
   TSAN_INTERCEPT(closedir);
 
