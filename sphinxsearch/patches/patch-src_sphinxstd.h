$NetBSD: patch-src_sphinxstd.h,v 1.1 2013/02/21 12:24:13 jonperkin Exp $

Portability fixes.

--- src/sphinxstd.h.orig	2012-10-19 09:48:07.000000000 +0000
+++ src/sphinxstd.h
@@ -64,6 +64,11 @@ typedef int __declspec("SAL_nokernel") _
 #include <pthread.h>
 #endif
 
+#ifdef __NetBSD__
+#define pthread_mutexattr_setpshared(m,a)	(0)
+#define pthread_condattr_setpshared(m,a)	(0)
+#endif
+
 /////////////////////////////////////////////////////////////////////////////
 // COMPILE-TIME CHECKS
 /////////////////////////////////////////////////////////////////////////////
