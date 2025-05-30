$NetBSD: patch-gcc_ada_adaint.c,v 1.1 2025/04/28 22:00:00 dkazankov Exp $

NetBSD does not use symbol versioning, which requires some functions
to be preprocessed in C. This patch adds those functions definitions,
not only for NetBSD, but for any other system too.

--- gcc/ada/adaint.c.orig	2025-04-25 08:18:00.000000000 +0000
+++ gcc/ada/adaint.c
@@ -853,7 +853,8 @@
 }
 
 #if defined (_WIN32) || defined (__linux__) || defined (__sun__) \
-  || defined (__FreeBSD__) || defined(__DragonFly__) || defined (__QNX__)
+  || defined (__FreeBSD__) || defined(__DragonFly__) || defined (__QNX__) \
+  || defined (__NetBSD__)
 #define HAS_TARGET_WCHAR_T
 #endif
 
@@ -3714,6 +3715,69 @@
   */
 }
 
+#if defined(__NetBSD__)
+/* It's 2021, and NetBSD still doesn't use symbol versioning in their
+ * libraries.  They mimic this by having header macros rename the function
+ * at compile time.  If we don't wrap the functions, the osinte specification
+ * for NetBSD would need to import e.g. __sigaltstack14 instead of sigaltstack.
+ * By wrapping, new versions won't break gnat.
+ */
+int
+__gnat_sigemptyset (sigset_t *set) {
+   return sigemptyset (set);
+}
+int
+__gnat_sigfillset (sigset_t *set) {
+   return sigfillset (set);
+}
+int
+__gnat_sigaddset (sigset_t *set, int signo) {
+   return sigaddset (set, signo);
+}
+int
+__gnat_sigdelset (sigset_t *set, int signo) {
+   return sigdelset (set, signo);
+}
+int
+__gnat_sigismember (sigset_t *set, int signo) {
+   return sigismember (set, signo);
+}
+int
+__gnat_sigaltstack (const stack_t *ss, stack_t *oss) {
+   return sigaltstack (ss, oss);
+}
+int
+__gnat_sigaction (int sig, const struct sigaction *act, struct sigaction *oact) {
+   return sigaction (sig, act, oact);
+}
+int
+__gnat_clock_getres (clockid_t clock_id, struct timespec *res) {
+   return clock_getres (clock_id, res);
+}
+int
+__gnat_clock_gettime (clockid_t clock_id, struct timespec *tp) {
+   return clock_gettime (clock_id, tp);
+}
+int
+__gnat_nanosleep (const struct timespec *rqtp, struct timespec *rmtp) {
+   return nanosleep (rqtp, rmtp);
+}
+int
+__gnat_gettimeofday (struct timeval * tp, struct timezone * tzp) {
+   return gettimeofday (tp, tzp);
+}
+
+int
+__gnat_select(int nfds, fd_set * readfds, fd_set * writefds,
+              fd_set * exceptfds, struct timeval * timeout) {
+   return select (nfds, readfds, writefds, exceptfds, timeout);
+}
+int
+__gnat_socket (int domain, int type, int protocol) {
+   return socket (domain, type, protocol);
+}
+#endif
+
 #ifdef __cplusplus
 }
 #endif
