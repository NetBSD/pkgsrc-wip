$NetBSD$

The volatile macro is used in {amd64,i386,machine}/mcontext.h on NetBSD.

--- src/main.h.orig	2016-05-11 09:22:11.668807995 +0000
+++ src/main.h
@@ -40,7 +40,7 @@
 //  fixes compile with apple headers
 /*** This breaks both android and Windows video... but it's needed to fix complation in clang (Cocoa & asan)
  ***  TODO fix them?
-#ifndef __OBJC__
+##if !defined(__OBJC__) && !defined(__NetBSD__)
 #define volatile(x) (*((volatile typeof(x)*)&x))
 #endif */
 
