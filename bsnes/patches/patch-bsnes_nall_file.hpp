$NetBSD: patch-bsnes_nall_file.hpp,v 1.1 2012/09/06 02:42:53 othyro Exp $

Work around Linuxism.

--- bsnes/nall/file.hpp.orig	2012-08-09 22:23:15.000000000 +0000
+++ bsnes/nall/file.hpp
@@ -8,6 +8,10 @@
 #include <nall/windows/utf8.hpp>
 #include <nall/stream/memory.hpp>
 
+#ifndef stat64
+#define stat64 stat
+#endif
+
 namespace nall {
   inline FILE* fopen_utf8(const string &utf8_filename, const char *mode) {
     #if !defined(_WIN32)
