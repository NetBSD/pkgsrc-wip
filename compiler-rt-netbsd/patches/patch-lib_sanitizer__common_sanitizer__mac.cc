$NetBSD$

--- lib/sanitizer_common/sanitizer_mac.cc.orig	2018-05-10 23:16:36.000000000 +0000
+++ lib/sanitizer_common/sanitizer_mac.cc
@@ -340,6 +340,10 @@ void ReExec() {
   UNIMPLEMENTED();
 }
 
+void CheckASLR() {
+  // Do nothing
+}
+
 uptr GetPageSize() {
   return sysconf(_SC_PAGESIZE);
 }
