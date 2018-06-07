$NetBSD$

--- lib/esan/esan_interceptors.cpp.orig	2018-04-25 21:13:40.000000000 +0000
+++ lib/esan/esan_interceptors.cpp
@@ -316,13 +316,6 @@ INTERCEPTOR(int, unlink, char *path) {
   return REAL(unlink)(path);
 }
 
-INTERCEPTOR(int, puts, const char *s) {
-  void *ctx;
-  COMMON_INTERCEPTOR_ENTER(ctx, puts, s);
-  COMMON_INTERCEPTOR_READ_RANGE(ctx, s, internal_strlen(s));
-  return REAL(puts)(s);
-}
-
 INTERCEPTOR(int, rmdir, char *path) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, rmdir, path);
@@ -495,7 +488,6 @@ void initializeInterceptors() {
   INTERCEPT_FUNCTION(unlink);
   INTERCEPT_FUNCTION(fread);
   INTERCEPT_FUNCTION(fwrite);
-  INTERCEPT_FUNCTION(puts);
   INTERCEPT_FUNCTION(rmdir);
 
   ESAN_MAYBE_INTERCEPT_SIGNAL;
