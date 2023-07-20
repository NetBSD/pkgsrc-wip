$NetBSD$

gettext-0.22 API change

--- src/library/utils/src/utils.c.orig	2023-03-24 08:02:05.000000000 +0900
+++ src/library/utils/src/utils.c	2023-07-20 22:20:01.864010902 +0900
@@ -27,6 +27,12 @@
 
 #include "utils.h"
 
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
+
+
 /* from src/main/eval.c */
 SEXP do_Rprof(SEXP args);
 
