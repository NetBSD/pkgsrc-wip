$NetBSD$

--- lib/sanitizer_common/sanitizer_linux.cc.orig	2018-10-01 21:40:24.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux.cc
@@ -591,7 +591,7 @@ static void GetArgsAndEnv(char ***argv, 
   // this information. See also <sys/exec.h>.
   ps_strings *pss;
   size_t sz = sizeof(pss);
-  if (sysctlbyname("kern.ps_strings", &pss, &sz, NULL, 0) == -1) {
+  if (internal_sysctlbyname("kern.ps_strings", &pss, &sz, NULL, 0) == -1) {
     Printf("sysctl kern.ps_strings failed\n");
     Die();
   }
@@ -796,6 +796,16 @@ int internal_sysctl(const int *name, uns
   return sysctl(name, namelen, oldp, (size_t *)oldlenp, newp, (size_t)newlen);
 #endif
 }
+
+int internal_sysctlbyname(const char *sname, void *oldp, uptr *oldlenp,
+                          const void *newp, uptr newlen) {
+#if SANITIZER_OPENBSD
+  return sysctlbyname(sname, oldp, (size_t *)oldlenp, (void *)newp,
+                     (size_t)newlen);
+#else
+  return sysctlbyname(sname, oldp, (size_t *)oldlenp, newp, (size_t)newlen);
+#endif
+}
 #endif
 
 #if SANITIZER_LINUX
