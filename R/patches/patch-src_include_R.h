$NetBSD$

gettext-0.22 API change

--- src/include/R.h.orig	2023-03-24 08:02:03.000000000 +0900
+++ src/include/R.h	2023-07-20 23:52:00.503517487 +0900
@@ -28,6 +28,14 @@
 # define USING_R
 #endif
 
+
+# ifndef _LIBINTL_H
+#   define _INTL_REDIRECT_MACROS
+#   include "gettext/libintl.h"
+# endif
+
+
+
 /* same as Rmath.h: needed for cospi etc */
 #ifndef __STDC_WANT_IEC_60559_FUNCS_EXT__
 # define __STDC_WANT_IEC_60559_FUNCS_EXT__ 1
