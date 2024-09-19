$NetBSD$

Properly include alloca(3).

--- src/xplugd.c.orig	2020-07-08 09:02:10.000000000 +0000
+++ src/xplugd.c
@@ -23,7 +23,17 @@
  */
 
 #define SYSLOG_NAMES
-#include <alloca.h>
+#ifdef STDC_HEADERS
+# include <stdlib.h>
+# include <stddef.h>
+#else
+# ifdef HAVE_STDLIB_H
+#  include <stdlib.h>
+# endif
+#endif
+#ifdef HAVE_ALLOCA_H
+# include <alloca.h>
+#endif
 #include <glob.h>
 #include "xplugd.h"
 
