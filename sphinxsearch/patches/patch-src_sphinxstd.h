$NetBSD: patch-src_sphinxstd.h,v 1.3 2014/03/05 10:31:09 fhajny Exp $

Portability fixes.

--- src/sphinxstd.h.orig	2014-01-22 15:16:21.000000000 +0000
+++ src/sphinxstd.h
@@ -75,6 +75,13 @@ typedef int __declspec("SAL_nokernel") _
 #endif
 #endif
 
+#ifdef __NetBSD__
+#define pthread_mutexattr_setpshared(m,a)	(0)
+#define pthread_condattr_setpshared(m,a)	(0)
+#include "sys/signal.h"
+#define PTHREAD_STACK_MIN MINSIGSTKSZ
+#endif
+
 /////////////////////////////////////////////////////////////////////////////
 // COMPILE-TIME CHECKS
 /////////////////////////////////////////////////////////////////////////////
