$NetBSD: patch-nall_file.hpp,v 1.2 2012/06/03 12:39:10 othyro Exp $

Work around Linuxism.

--- nall/file.hpp.orig	2012-05-11 19:58:15.000000000 +0000
+++ nall/file.hpp
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
