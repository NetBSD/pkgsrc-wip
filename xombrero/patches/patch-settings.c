$NetBSD: patch-settings.c,v 1.1 2013/11/15 19:54:33 asau Exp $

--- settings.c.orig	2012-09-15 16:45:08.000000000 +0000
+++ settings.c
@@ -23,6 +23,12 @@
 #include <xombrero.h>
 #include "tooltip.h"
 
+#if defined(__NetBSD__)
+long long
+strtonum(const char *numstr, long long minval, long long maxval,
+	 const char **errstrp);
+#endif
+
 /* globals */
 SoupURI			*proxy_uri = NULL;
 PangoFontDescription	*cmd_font;
