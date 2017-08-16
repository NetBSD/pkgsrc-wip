$NetBSD$

Don't discriminate against unix-like systems.

--- realpath.c.orig	2012-12-05 00:18:04.000000000 +0000
+++ realpath.c
@@ -6,9 +6,7 @@
 #include <fcntl.h>
 #include <string.h>
 #include <unistd.h>
-#if defined(__AROS__) || defined(__linux__) || defined(__GLIBC__)|| defined(__MINT__)
 #include <limits.h>
-#endif
 
 #if defined(__AROS__) || defined(__BEOS__) || defined(__MORPHOS__) || defined(__GP2X__) || defined(__WIZ__) || defined(__CAANOO__) || defined(__amigaos__)
 // These platforms don't have realpath().
