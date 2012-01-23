$NetBSD: patch-nall_file.hpp,v 1.1 2012/01/23 09:31:11 thomasklausner Exp $

Work around Linuxism.

--- nall/file.hpp.orig	2012-01-02 11:07:59.000000000 +0000
+++ nall/file.hpp
@@ -7,6 +7,10 @@
 #include <nall/utility.hpp>
 #include <nall/windows/utf8.hpp>
 
+#ifndef stat64
+#define stat64 stat
+#endif
+
 namespace nall {
   inline FILE* fopen_utf8(const string &utf8_filename, const char *mode) {
     #if !defined(_WIN32)
