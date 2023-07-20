$NetBSD$

gettext-0.22 API change

--- src/library/tools/src/http.c.orig	2018-09-25 17:45:10.000000000 +0900
+++ src/library/tools/src/http.c	2023-07-20 22:02:16.548699208 +0900
@@ -21,6 +21,10 @@
 #include <Rinternals.h>
 #include "tools.h"
 
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
 
 extern int extR_HTTPDCreate(const char *ip, int port);
 extern void extR_HTTPDStop(void);
