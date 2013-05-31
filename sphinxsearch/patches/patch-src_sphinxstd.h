$NetBSD: patch-src_sphinxstd.h,v 1.2 2013/05/31 20:45:15 fhajny Exp $

Portability fixes.

--- src/sphinxstd.h.orig	2013-04-18 15:15:44.000000000 +0000
+++ src/sphinxstd.h
@@ -67,6 +67,11 @@ typedef int __declspec("SAL_nokernel") _
 #endif
 #endif
 
+#ifdef __NetBSD__
+#define pthread_mutexattr_setpshared(m,a)	(0)
+#define pthread_condattr_setpshared(m,a)	(0)
+#endif
+
 /////////////////////////////////////////////////////////////////////////////
 // COMPILE-TIME CHECKS
 /////////////////////////////////////////////////////////////////////////////
