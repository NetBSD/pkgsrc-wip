$NetBSD$


--- src/library/graphics/src/stem.c.orig	2018-09-25 17:45:05.000000000 +0900
+++ src/library/graphics/src/stem.c	2023-07-20 22:26:30.332036921 +0900
@@ -33,8 +33,12 @@
 #include <R_ext/Arith.h> /* for R_FINITE */
 
 #ifdef ENABLE_NLS
-#include <libintl.h>
-#define _(String) dgettext ("graphics", String)
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
+
+#define _(String) libintl_dgettext ("graphics", String)
 #else
 #define _(String) (String)
 #endif
