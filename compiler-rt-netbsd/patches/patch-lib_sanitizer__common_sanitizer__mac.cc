$NetBSD$

--- lib/sanitizer_common/sanitizer_mac.cc.orig	2018-08-21 21:25:40.000000000 +0000
+++ lib/sanitizer_common/sanitizer_mac.cc
@@ -213,6 +213,11 @@ int internal_fork() {
   return fork();
 }
 
+int internal_sysctl(const int *name, unsigned int namelen, void *oldp,
+                    uptr *oldlenp, const void *newp, uptr newlen) {
+  return sysctl(name, namelen, oldp, oldlenp, newp, newlen);
+}
+
 int internal_forkpty(int *amaster) {
   int master, slave;
   if (openpty(&master, &slave, nullptr, nullptr, nullptr) == -1) return -1;
@@ -499,9 +504,9 @@ MacosVersion GetMacosVersionInternal() {
   uptr len = 0, maxlen = sizeof(version) / sizeof(version[0]);
   for (uptr i = 0; i < maxlen; i++) version[i] = '\0';
   // Get the version length.
-  CHECK_NE(sysctl(mib, 2, 0, &len, 0, 0), -1);
+  CHECK_NE(internal_sysctl(mib, 2, 0, &len, 0, 0), -1);
   CHECK_LT(len, maxlen);
-  CHECK_NE(sysctl(mib, 2, version, &len, 0, 0), -1);
+  CHECK_NE(internal_sysctl(mib, 2, version, &len, 0, 0), -1);
   switch (version[0]) {
     case '9': return MACOS_VERSION_LEOPARD;
     case '1': {
