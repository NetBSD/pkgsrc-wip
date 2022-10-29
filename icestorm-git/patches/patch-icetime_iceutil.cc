$NetBSD$

Tell iceutil that it should use /proc on NetBSD.

--- icetime/iceutil.cc.orig	2022-09-15 10:37:29.000000000 +0000
+++ icetime/iceutil.cc
@@ -38,7 +38,7 @@
 
 #include <limits.h>
 
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__NetBSD__)
 std::string proc_self_dirname()
 {
 	char path[PATH_MAX];
