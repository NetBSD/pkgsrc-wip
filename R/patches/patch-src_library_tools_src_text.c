$NetBSD$

gettext-0.22 API change

--- src/library/tools/src/text.c.orig	2022-05-30 07:15:01.000000000 +0900
+++ src/library/tools/src/text.c	2023-07-20 22:00:39.895082036 +0900
@@ -25,11 +25,18 @@
 #include <R.h>
 #include "tools.h"
 
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
+
 #include <stdlib.h> /* for MB_CUR_MAX */
 #include <wchar.h>
 LibExtern Rboolean mbcslocale;
 LibExtern int R_MB_CUR_MAX;
 
+
+
 size_t Rf_mbrtowc(wchar_t *wc, const char *s, size_t n, mbstate_t *ps);
 
 /* .Call, so manages R_alloc stack */
