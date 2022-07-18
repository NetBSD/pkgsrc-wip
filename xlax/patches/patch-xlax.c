$NetBSD$

Fix warnings about prepocessor defined macros. 
Use libbsd on Linux to support strlcpy().

--- xlax.c.orig	2008-07-31 20:18:25.000000000 +0000
+++ xlax.c
@@ -30,6 +30,11 @@
  *
  */
 
+#ifdef __linux__
+#include <bsd/string.h>
+#endif
+
+#include "stddef.h"
 #include "xlax.h"
 #include "vroot.h"
 
