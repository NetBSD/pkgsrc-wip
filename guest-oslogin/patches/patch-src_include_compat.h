$NetBSD$

Support NetBSD like FreeBSD

--- src/include/compat.h.orig	2019-10-23 17:48:13.000000000 +0000
+++ src/include/compat.h
@@ -15,7 +15,7 @@
 #ifndef OSLOGIN_COMPAT_H
 #define OSLOGIN_COMPAT_H
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 
 #include <nsswitch.h>
 
