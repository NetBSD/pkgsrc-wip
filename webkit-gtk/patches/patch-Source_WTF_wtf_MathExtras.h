$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.2 2015/03/28 18:39:36 leot1990 Exp $

Avoid broken section for SunOS/gcc.

--- Source/WTF/wtf/MathExtras.h.orig	2015-03-23 08:08:04.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -84,7 +84,7 @@ inline double wtf_ceil(double x) { retur
 
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
