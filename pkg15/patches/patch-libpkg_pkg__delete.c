$NetBSD: patch-libpkg_pkg__delete.c,v 1.1 2015/04/05 20:06:53 khorben Exp $

--- libpkg/pkg_delete.c.orig	2015-04-05 08:31:08.000000000 +0000
+++ libpkg/pkg_delete.c
@@ -47,10 +47,10 @@
 #include "private/pkgdb.h"
 #include "private/utils.h"
 
-#if defined(__APPLE__)
-#define NOCHANGESFLAGS	(UF_IMMUTABLE | UF_APPEND | SF_IMMUTABLE | SF_APPEND)
-#else
+#if defined(UF_NOUNLINK)
 #define NOCHANGESFLAGS	(UF_IMMUTABLE | UF_APPEND | UF_NOUNLINK | SF_IMMUTABLE | SF_APPEND | SF_NOUNLINK)
+#else
+#define NOCHANGESFLAGS	(UF_IMMUTABLE | UF_APPEND | SF_IMMUTABLE | SF_APPEND)
 #endif
 
 int
