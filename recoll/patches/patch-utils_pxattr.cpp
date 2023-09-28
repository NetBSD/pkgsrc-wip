$NetBSD$

--- utils/pxattr.cpp.orig	2023-05-12 08:19:26.000000000 +0000
+++ utils/pxattr.cpp
@@ -64,7 +64,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/extattr.h>
 #include <sys/uio.h>
 #elif defined(PXALINUX)
