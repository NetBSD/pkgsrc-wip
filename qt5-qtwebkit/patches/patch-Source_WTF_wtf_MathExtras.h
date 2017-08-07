$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.1 2016/07/22 10:14:17 jperkin Exp $

Fix SunOS build.

--- Source/WTF/wtf/MathExtras.h.orig	2017-06-04 20:16:06.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -75,7 +75,7 @@ const double sqrtOfTwoDouble = M_SQRT2;
 const float sqrtOfTwoFloat = static_cast<float>(M_SQRT2);
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
