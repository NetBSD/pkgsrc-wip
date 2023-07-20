$NetBSD$

gettext-0.22 API change

--- src/library/tools/src/pdscan.c.orig	2022-03-25 08:02:05.000000000 +0900
+++ src/library/tools/src/pdscan.c	2023-07-20 22:03:41.827382802 +0900
@@ -22,6 +22,12 @@
 #include <ctype.h>
 #include "tools.h"
 
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
+
+
 static SEXP package_dependencies_scan_one(SEXP this) {
     SEXP y;
     Rboolean save, skip;
