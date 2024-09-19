$NetBSD: patch-src_base_platform_platform.h,v 1.1 2014/08/25 13:22:01 fhajny Exp $

Avoid conflicting with definitions in GCC includes.

--- src/base/platform/platform.h.orig	2014-08-08 13:04:31.000000000 +0000
+++ src/base/platform/platform.h
@@ -29,7 +29,7 @@
 #include "src/base/platform/mutex.h"
 #include "src/base/platform/semaphore.h"
 
-#ifdef __sun
+#if defined(__sun) && !defined(_GLIBCXX_USE_C99_MATH)
 # ifndef signbit
 namespace std {
 int signbit(double x);
