$NetBSD$

Fix build on SmartOS

--- openbsd-compat/imsg-buffer.c.orig	2020-05-21 19:06:04.000000000 +0000
+++ openbsd-compat/imsg-buffer.c
@@ -16,6 +16,15 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+/* needed for CMSG_* functions on SunOS */
+#if defined(__sun)
+#if (__STDC_VERSION__ - 0 < 199901L)
+#define _XOPEN_SOURCE 500
+#else
+#define _XOPEN_SOURCE 600
+#endif
+#endif
+
 #include "includes.h"
 
 #include <sys/param.h>
@@ -26,7 +35,7 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
-#ifndef HAVE_EXPLICIT_BZERO
+#if defined (HAVE_EXPLICIT_BZERO) || (defined(sun) || defined(__sun))
 #include <strings.h>
 #endif
 #include <unistd.h>
