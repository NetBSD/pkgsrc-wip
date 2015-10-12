$NetBSD: patch-an,v 1.2 2011/12/07 16:05:59 roy Exp $

- Appease prototype warnings.
- Remove unnecessary ops.

--- canuum/canna.c.orig	2003-09-17 08:50:52.000000000 +0000
+++ canuum/canna.c
@@ -52,4 +52,16 @@ static char rcsid[] = "$Id: canna.c,v 1.
 #endif
 
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#if STDC_HEADERS
+#  include <string.h>
+#else
+#  if HAVE_STRINGS_H
+#    include <strings.h>
+#  endif
+#endif /* STDC_HEADERS */
+
 #include "commonhd.h"
 #include "sdefine.h"
@@ -95,6 +107,4 @@ static char rcsid[] = "$Id: canna.c,v 1.
 #define NOREDRAW      0
 
-extern	int	errno;
-
 static int maxmodelen;
 static int maxwidth = 0;
@@ -1271,5 +1281,5 @@ int flag;
 #endif
 
-  resetterm();
+  reset_shell_mode();
 #endif
 
