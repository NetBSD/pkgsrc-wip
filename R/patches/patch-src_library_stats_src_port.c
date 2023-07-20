$NetBSD$

gettext-0.22 API Change

--- src/library/stats/src/port.c.orig	2023-03-24 08:02:04.000000000 +0900
+++ src/library/stats/src/port.c	2023-07-21 06:08:04.881125778 +0900
@@ -23,6 +23,11 @@
 #include <R_ext/BLAS.h>
 #include <R_ext/Print.h>
 
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
+
 				/* names of 1-based indices into iv and v */
 #define AFCTOL  31
 #define ALGSAV  51
