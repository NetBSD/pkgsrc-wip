$NetBSD: patch-jsmath.cpp,v 1.1 2014/02/06 15:12:18 fhajny Exp $

--- jsmath.cpp.orig	2013-10-29 20:40:20.000000000 +0000
+++ jsmath.cpp
@@ -244,7 +244,7 @@ js::ecmaAtan2(double y, double x)
     }
 #endif
 
-#if defined(SOLARIS) && defined(__GNUC__)
+#if defined(notSOLARIS) && defined(__GNUC__)
     if (y == 0) {
         if (IsNegativeZero(x))
             return js_copysign(M_PI, y);
