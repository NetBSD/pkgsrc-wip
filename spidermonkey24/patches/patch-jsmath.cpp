$NetBSD: patch-jsmath.cpp,v 1.1 2014/02/06 15:12:18 fhajny Exp $

--- jsmath.cpp.orig	2013-09-10 03:43:36.000000000 +0000
+++ jsmath.cpp
@@ -244,7 +244,7 @@ js::ecmaAtan2(double y, double x)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (y == 0) {
         if (IsNegativeZero(x))
             return js_copysign(M_PI, y);
