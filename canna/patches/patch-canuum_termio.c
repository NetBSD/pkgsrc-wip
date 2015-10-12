$NetBSD: patch-ap,v 1.1 2011/12/07 16:05:59 roy Exp $

- Appease prototype warnings.
- Remove unnecessary ops.

--- canuum/termio.c.orig	2003-12-27 17:15:21.000000000 +0000
+++ canuum/termio.c
@@ -36,6 +36,11 @@
 #include <stdio.h>
 #if STDC_HEADERS
 #  include <stdlib.h>
+#  include <string.h>
+#else
+#  if HAVE_STRINGS_H
+#    include <strings.h>
+#  endif
 #endif /* STDC_HEADERS */
 
 #include "commonhd.h"
@@ -175,7 +180,6 @@ openTermData ()
 void
 closeTermData ()
 {
-  resetterm ();
   reset_shell_mode ();
 }
 
