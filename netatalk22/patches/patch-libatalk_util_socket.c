$NetBSD: patch-libatalk_util_socket.c,v 1.1 2011/07/28 14:41:18 hfath Exp $

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
