$NetBSD: patch-rpcemu.h,v 1.2 2014/11/03 22:01:05 ryo-on Exp $

* Support NetBSD

--- rpcemu.h.orig	2014-10-22 18:23:44.000000000 +0000
+++ rpcemu.h
@@ -36,7 +36,7 @@
 #endif
 
 
-#if defined __MACH__ || defined __OpenBSD__
+#if defined __MACH__ || defined __OpenBSD__ || defined __NetBSD__
 #define fseeko64(_a, _b, _c) fseeko(_a, _b, _c)
 #define ftello64(stream) ftello(stream)
 #define fopen64(_a, _b) fopen(_a, _b)
