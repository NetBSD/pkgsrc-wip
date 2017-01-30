$NetBSD: patch-hwaccess.c,v 1.1 2016/12/22 21:07:17 joerg Exp $

It is UB whether define() is not handled inside macro expansions.

--- hwaccess.c.orig	2016-03-06 22:32:16.000000000 +0000
+++ hwaccess.c
@@ -37,9 +37,21 @@
 #error "Unknown operating system"
 #endif
 
-#define USE_IOPL	(IS_LINUX || IS_MACOSX || defined(__NetBSD__) || defined(__OpenBSD__))
-#define USE_DEV_IO	(defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__))
-#define USE_IOPERM	(defined(__gnu_hurd__))
+#if	IS_LINUX || IS_MACOSX || defined(__NetBSD__) || defined(__OpenBSD__)
+#define USE_IOPL	1
+#else
+#define USE_IOPL	0
+#endif
+#if	defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+#define USE_DEV_IO	1
+#else
+#define USE_DEV_IO	0
+#endif
+#if	defined(__gnu_hurd__)
+#define USE_IOPERM 1
+#else
+#define USE_IOPERM 0
+#endif
 
 #if USE_IOPERM
 #include <sys/io.h>
