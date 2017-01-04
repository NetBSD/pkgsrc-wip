$NetBSD$

Define __STDC_LIMIT_MACROS before stdint.h is included. This code segment
appears in build/include/compat.h, but that is too late on NetBSD.

--- source/m32exec.c.orig	2016-12-26 06:02:56.000000000 +0000
+++ source/m32exec.c
@@ -20,6 +20,13 @@ Foundation, Inc., 51 Franklin Street, Fi
 */
 //-------------------------------------------------------------------------
 
+#ifndef __STDC_FORMAT_MACROS
+# define __STDC_FORMAT_MACROS
+#endif
+#ifndef __STDC_LIMIT_MACROS
+# define __STDC_LIMIT_MACROS
+#endif
+
 #include <time.h>
 #include <stdlib.h>
 
