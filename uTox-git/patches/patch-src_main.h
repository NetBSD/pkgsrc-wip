$NetBSD$

The volatile macro is used in {amd64,i386,machine}/mcontext.h on NetBSD.

--- src/main.h.orig	2016-03-08 20:06:44.000000000 +0000
+++ src/main.h
@@ -33,7 +33,7 @@
 #define countof(x) (sizeof(x)/sizeof(*(x)))
 
 //  fixes compile with apple headers
-#ifndef __OBJC__
+#if !defined(__OBJC__) && !defined(__NetBSD__)
 #define volatile(x) (*((volatile typeof(x)*)&x))
 #endif
 
