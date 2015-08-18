$NetBSD: patch-src_libtcod_src_sys_c.c,v 1.1 2015/08/18 20:24:52 yhardy Exp $

Include the appropriate X11 headers on NetBSD as well

--- src/libtcod-1.5.2/src/sys_c.c.orig	2014-07-03 19:19:10.000000000 +0000
+++ src/libtcod-1.5.2/src/sys_c.c
@@ -31,7 +31,7 @@
 #include <sys/stat.h>
 #include <string.h>
 
-#if defined (__linux) && ! defined (__ANDROID__) || defined (__FreeBSD__)
+#if defined (__linux) && ! defined (__ANDROID__) || defined (__FreeBSD__) || defined (__NetBSD__)
 /* X11 stuff for clipboard support */
 #include <X11/Xlib.h>
 #include <X11/Xatom.h>
