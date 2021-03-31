$NetBSD$

# Use predefined macros

--- input-files.c.orig	2020-06-05 00:33:03 UTC
--- input-files.c.orig	2021-03-27 07:38:08.000000000 +0000
+++ input-files.c
@@ -48,7 +48,7 @@ FILE * f_subr_open(const char * fname, c
 #ifdef __MINGW32__
 		return fopen64(fname, mode);
 #else
-#if defined(__LP64__) || defined(_LP64) || defined(MACOS) 
+#if defined(__LP64__) || defined(_LP64) || defined(__APPLE__) || defined(__FreeBSD__)
 		return fopen(fname, mode);
 #else
 		return fopen64(fname, mode);
