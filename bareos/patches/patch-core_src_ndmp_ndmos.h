$NetBSD$

	Add NetBSD tag - not used for now

--- core/src/ndmp/ndmos.h.orig	2018-12-20 08:51:51.000000000 +0000
+++ core/src/ndmp/ndmos.h
@@ -94,7 +94,8 @@
 
 #ifndef _NDMOS_H
 #define _NDMOS_H
-
+#include <stdio.h>
+#include <string.h>
 /*
  * Silence compiler for known warnings.
  */
@@ -121,6 +122,7 @@
 #define NDMOS_IDENT(A,B,C,D)	(((A)<<24)+((B)<<16)+((C)<<8)+(D))
 
 #define NDMOS_ID_FREEBSD	NDMOS_IDENT('F','B','s','d')
+#define NDMOS_ID_NETBSD		NDMOS_IDENT('N','B','s','d')
 #define NDMOS_ID_SOLARIS	NDMOS_IDENT('S','o','l','a')
 #define NDMOS_ID_LINUX		NDMOS_IDENT('L','n','u','x')
 #define NDMOS_ID_IRIX		NDMOS_IDENT('I','R','I','X')
@@ -149,6 +151,10 @@
 #define NDMOS_ID	NDMOS_ID_FREEBSD
 #endif
 
+#ifdef HAVE_NETBSD_OS
+#define NDMOS_ID	NDMOS_ID_NETBSD
+#endif
+
 #ifdef HAVE_SUN_OS
 #define NDMOS_ID	NDMOS_ID_SOLARIS
 #endif
