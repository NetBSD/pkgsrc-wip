$NetBSD$

gettext-0.22 API change

--- src/extra/tre/regerror.c.orig	2018-09-25 08:46:40.000000000 +0000
+++ src/extra/tre/regerror.c	2023-07-20 06:58:53.519846262 +0000
@@ -22,7 +22,11 @@
 #include "tre.h"
 
 #ifdef HAVE_GETTEXT
-#include <libintl.h>
+# ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include <gettext/libintl.h>
+# endif
+
 #else
 #define dgettext(p, s) s
 #define gettext(s) s
