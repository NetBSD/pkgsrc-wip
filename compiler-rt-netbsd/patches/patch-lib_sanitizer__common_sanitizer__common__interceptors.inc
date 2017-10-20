$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2017-10-17 18:35:46.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -3795,7 +3795,7 @@ INTERCEPTOR(void, _exit, int status) {
 #define INIT__EXIT
 #endif
 
-#if SANITIZER_INTERCEPT_PHTREAD_MUTEX
+#if SANITIZER_INTERCEPT_PHTREAD_MUTEX && !SANITIZER_NETBSD
 INTERCEPTOR(int, pthread_mutex_lock, void *m) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, pthread_mutex_lock, m);
@@ -3828,6 +3828,13 @@ INTERCEPTOR(int, pthread_mutex_unlock, v
 #define INIT_PTHREAD_MUTEX_UNLOCK
 #endif
 
+__attribute__((constructor))
+static void
+yikes(void) {
+//  INIT_PTHREAD_MUTEX_LOCK;
+//  INIT_PTHREAD_MUTEX_UNLOCK;
+}
+
 #if SANITIZER_INTERCEPT_GETMNTENT || SANITIZER_INTERCEPT_GETMNTENT_R
 static void write_mntent(void *ctx, __sanitizer_mntent *mnt) {
   COMMON_INTERCEPTOR_WRITE_RANGE(ctx, mnt, sizeof(*mnt));
@@ -4405,7 +4412,7 @@ INTERCEPTOR(char *, tempnam, char *dir, 
 #define INIT_TEMPNAM
 #endif
 
-#if SANITIZER_INTERCEPT_PTHREAD_SETNAME_NP
+#if SANITIZER_INTERCEPT_PTHREAD_SETNAME_NP && !SANITIZER_NETBSD
 INTERCEPTOR(int, pthread_setname_np, uptr thread, const char *name) {
   void *ctx;
   COMMON_INTERCEPTOR_ENTER(ctx, pthread_setname_np, thread, name);
@@ -4414,6 +4421,18 @@ INTERCEPTOR(int, pthread_setname_np, upt
   return REAL(pthread_setname_np)(thread, name);
 }
 #define INIT_PTHREAD_SETNAME_NP COMMON_INTERCEPT_FUNCTION(pthread_setname_np);
+#elif SANITIZER_INTERCEPT_PTHREAD_SETNAME_NP && SANITIZER_NETBSD
+INTERCEPTOR(int, pthread_setname_np, uptr thread, const char *name, void *arg) {
+  void *ctx;
+  char newname[32]; // PTHREAD_MAX_NAMELEN_NP=32
+  int namelen;
+  COMMON_INTERCEPTOR_ENTER(ctx, pthread_setname_np, thread, name, arg);
+  namelen = internal_snprintf(newname, sizeof(newname), name, arg);
+  COMMON_INTERCEPTOR_READ_STRING(ctx, newname, namelen);
+  COMMON_INTERCEPTOR_SET_PTHREAD_NAME(ctx, thread, newname);
+  return REAL(pthread_setname_np)(thread, name, arg);
+}
+#define INIT_PTHREAD_SETNAME_NP COMMON_INTERCEPT_FUNCTION(pthread_setname_np);
 #else
 #define INIT_PTHREAD_SETNAME_NP
 #endif
@@ -6373,8 +6392,10 @@ static void InitializeCommonInterceptors
   INIT_SIGPROCMASK;
   INIT_BACKTRACE;
   INIT__EXIT;
+#if !SANITIZER_NETBSD
   INIT_PTHREAD_MUTEX_LOCK;
   INIT_PTHREAD_MUTEX_UNLOCK;
+#endif
   INIT_GETMNTENT;
   INIT_GETMNTENT_R;
   INIT_STATFS;
