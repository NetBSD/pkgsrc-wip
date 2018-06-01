$NetBSD$

--- lib/sanitizer_common/sanitizer_win.cc.orig	2018-05-10 23:16:35.000000000 +0000
+++ lib/sanitizer_common/sanitizer_win.cc
@@ -1025,6 +1025,10 @@ void MaybeReexec() {
   // No need to re-exec on Windows.
 }
 
+void CheckASLR() {
+  // Do nothing
+}
+
 char **GetArgv() {
   // FIXME: Actually implement this function.
   return 0;
