$NetBSD: patch-Source_WTF_wtf_MathExtras.h,v 1.1 2015/01/24 01:33:08 leot1990 Exp $

Avoid broken section for SunOS/gcc.

--- Source/WTF/wtf/MathExtras.h.orig	2015-01-15 09:40:35.000000000 +0000
+++ Source/WTF/wtf/MathExtras.h
@@ -76,7 +76,7 @@ inline double wtf_ceil(double x) { retur
 
 #endif
 
-#if OS(SOLARIS)
+#if OS(notSOLARIS)
 
 namespace std {
 
