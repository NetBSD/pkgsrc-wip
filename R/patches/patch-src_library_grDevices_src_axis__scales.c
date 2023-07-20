$NetBSD$

gettext-0.22 API change

--- src/library/grDevices/src/axis_scales.c.orig	2022-03-25 08:02:04.000000000 +0900
+++ src/library/grDevices/src/axis_scales.c	2023-07-20 21:55:19.787805362 +0900
@@ -27,6 +27,12 @@
 
 #include "grDevices.h"
 
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
+
+
 SEXP R_CreateAtVector(SEXP axp, SEXP usr, SEXP nint, SEXP is_log)
 {
     int nint_v = asInteger(nint);
