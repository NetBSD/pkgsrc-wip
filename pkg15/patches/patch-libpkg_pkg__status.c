$NetBSD: patch-libpkg_pkg__status.c,v 1.1 2015/02/21 12:21:00 khorben Exp $

Let the default LOCALBASE variable be overridden at compile-time

--- libpkg/pkg_status.c.orig	2015-02-20 00:10:44.000000000 +0000
+++ libpkg/pkg_status.c
@@ -38,7 +38,9 @@
 #include "pkg.h"
 
 
+#ifndef _LOCALBASE
 #define _LOCALBASE	"/usr/local"
+#endif
 
 static bool is_exec_at_localbase(const char *progname);
 
