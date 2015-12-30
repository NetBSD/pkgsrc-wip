$NetBSD$

The volatile macro is used in {amd64,i386,machine}/mcontext.h on NetBSD.

--- src/main.h.orig	2015-12-29 21:26:38.000000000 +0000
+++ src/main.h
@@ -30,7 +30,7 @@
 #define countof(x) (sizeof(x)/sizeof(*(x)))
 
 //  fixes compile with apple headers
-#ifndef __OBJC__
+#if !defined(__OBJC__) && !defined(__NetBSD__)
 #define volatile(x) (*((volatile typeof(x)*)&x))
 #endif
 
