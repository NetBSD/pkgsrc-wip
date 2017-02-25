$NetBSD$

--- src/common.c.orig	2017-01-23 19:49:04.000000000 +0000
+++ src/common.c
@@ -3,10 +3,14 @@
 #ifdef __APPLE__
 #define INHERIT_NONE 0
 #endif /* __APPLE__ */
-#if defined(__FreeBSD__) || defined(__APPLE__)
+#if defined(__FreeBSD__) || defined(__APPLE__) || defined(__NetBSD__)
 #    define O_NOATIME     0
 #    define MADV_DONTFORK INHERIT_NONE
-#endif /* __FreeBSD__ || __APPLE__*/
+#endif /* __FreeBSD__ || __APPLE__ || __NetBSD__*/
+
+#ifdef __NetBSD__
+#include <lwp.h>
+#endif
 
 char *global_host_prefix = "";
 int enable_ksm = 1;
@@ -1035,9 +1039,11 @@ pid_t gettid(void) {
     uint64_t curthreadid;
     pthread_threadid_np(NULL, &curthreadid);
     return (pid_t)curthreadid;
+#elif defined(__NetBSD__)
+    return _lwp_self();
 #else
     return (pid_t)syscall(SYS_gettid);
-#endif /* __FreeBSD__, __APPLE__*/
+#endif /* __FreeBSD__, __APPLE__, __NetBSD__*/
 }
 
 char *fgets_trim_len(char *buf, size_t buf_size, FILE *fp, size_t *len) {
