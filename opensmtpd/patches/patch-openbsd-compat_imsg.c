$NetBSD$

Fix build on SmartOS

--- openbsd-compat/imsg.c.orig	2023-06-27 14:04:38.000000000 +0000
+++ openbsd-compat/imsg.c
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
 
 #include <sys/types.h>
