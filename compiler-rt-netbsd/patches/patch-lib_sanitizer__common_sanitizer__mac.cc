$NetBSD$

--- lib/sanitizer_common/sanitizer_mac.cc.orig	2018-10-01 21:40:24.000000000 +0000
+++ lib/sanitizer_common/sanitizer_mac.cc
@@ -219,6 +219,12 @@ int internal_sysctl(const int *name, uns
                 const_cast<void *>(newp), (size_t)newlen);
 }
 
+int internal_sysctlbyname(const char *sname, void *oldp, uptr *oldlenp,
+                          const void *newp, uptr newlen) {
+  return sysctlbyname(sname, oldp, (size_t *)oldlenp, const_cast<void *>(newp),
+                      (size_t)newlen);
+}
+
 int internal_forkpty(int *amaster) {
   int master, slave;
   if (openpty(&master, &slave, nullptr, nullptr, nullptr) == -1) return -1;
