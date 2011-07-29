$NetBSD: patch-libatalk_util_socket.c,v 1.2 2011/07/29 12:18:52 hfath Exp $

Do not #define standards for *BSD since they restrict namespace,
and things like u_{byte,short} do not get defined.

--- libatalk/util/socket.c.orig	2011-07-27 11:55:39.000000000 +0000
+++ libatalk/util/socket.c
@@ -21,7 +21,7 @@
 #include "config.h"
 #endif /* HAVE_CONFIG_H */
 
-#if !defined(__FreeBSD__)
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 # ifndef _XOPEN_SOURCE
 #  define _XOPEN_SOURCE 600
 # endif
