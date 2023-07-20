$NetBSD$

gettext-0.22 API change

--- src/library/grDevices/src/devQuartz.c.orig	2023-04-04 07:15:01.000000000 +0900
+++ src/library/grDevices/src/devQuartz.c	2023-07-20 22:43:32.558162937 +0900
@@ -25,6 +25,11 @@
 #include <config.h>
 #endif
 
+#ifndef _LIBINTL_H
+#  define _INTL_REDIRECT_MACROS
+#  include "gettext/libintl.h"
+#endif
+
 #if HAVE_AQUA
 
 #include <Defn.h>
