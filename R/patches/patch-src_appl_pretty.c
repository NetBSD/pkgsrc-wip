$NetBSD$

gettext-0.22 API change

--- src/appl/pretty.c.orig	2023-03-23 23:02:02.000000000 +0000
+++ src/appl/pretty.c	2023-07-20 06:48:51.271243263 +0000
@@ -45,10 +45,10 @@
 #endif
 
 #ifdef ENABLE_NLS
-#include <libintl.h>
-#define _(String) gettext (String)
-#else
-#define _(String) (String)
+/* starting gettext-0.22, some symbols are hidden, and make them visible */
+#define _INTL_REDIRECT_MACROS
+#include <gettext/libintl.h>
 #endif
+#define _(String) (String)
 
 #include <math.h>
