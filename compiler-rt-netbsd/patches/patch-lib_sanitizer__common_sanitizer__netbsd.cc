$NetBSD$

--- lib/sanitizer_common/sanitizer_netbsd.cc.orig	2018-10-01 21:40:24.000000000 +0000
+++ lib/sanitizer_common/sanitizer_netbsd.cc
@@ -297,6 +297,14 @@ DEFINE_INTERNAL(int, sysctl, const int *
   return __sysctl(name, namelen, oldp, (size_t *)oldlenp, newp, (size_t)newlen);
 }
 
+DEFINE_INTERNAL(int, sysctlbyname, const char *sname, void *oldp,
+                uptr *oldlenp, const void *newp, uptr newlen) {
+  DEFINE__REAL(int, sysctlbyname, const char *a, void *b, size_t *c,
+               const void *d, size_t e);
+  return _REAL(sysctlbyname, sname, oldp, (size_t *)oldlenp, newp,
+               (size_t)newlen);
+}
+
 DEFINE_INTERNAL(uptr, sigprocmask, int how, __sanitizer_sigset_t *set,
                 __sanitizer_sigset_t *oldset) {
   CHECK(&_sys___sigprocmask14);
