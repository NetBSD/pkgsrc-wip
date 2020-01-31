$NetBSD$

NetBSD is totally different. Patch the whole file out for now.

--- tuntap.c.orig	2019-09-10 18:06:20.000000000 +0000
+++ tuntap.c
@@ -30,7 +30,7 @@
 #include "hstdinc.h"
 
 /* jbs 1/19/2008 added ifdef on __SOLARIS__ */
-#if !defined(__SOLARIS__)
+#if !defined(__SOLARIS__) && !defined(__NetBSD__)
 
 #include "hercules.h"
 #include "tuntap.h"
