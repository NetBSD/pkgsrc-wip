$NetBSD: patch-src_util_check.c,v 1.1 2013/04/03 21:21:05 outpaddling Exp $

--- src/util/check.c.orig	2013-04-03 21:01:44.000000000 +0000
+++ src/util/check.c
@@ -0,0 +1,15 @@
+#include <libguile.h>
+
+void
+scm_mpb_error (const char *file, int line, const char *message)
+{
+  char buf[256];
+  sprintf (buf, "%s, line %d", file, line);
+  scm_error(
+    scm_string_to_symbol (scm_makfrom0str("mpb-error")),
+    buf, 
+    message, 
+    SCM_BOOL_F, /* no args */
+    SCM_BOOL_F  /* no rest */
+  );
+}
