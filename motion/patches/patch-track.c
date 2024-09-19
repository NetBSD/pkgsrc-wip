$NetBSD$

Portability: not fixed up by configure

--- track.c.orig	2016-10-25 02:39:24.000000000 +0100
+++ track.c	2017-06-10 17:55:31.000000000 +0100
@@ -6,7 +6,11 @@
  *    This program is published under the GNU Public license
  */
 #ifdef MOTION_V4L2
+#ifdef __NetBSD__
+#include <sys/videoio.h>
+#else
 #include <linux/videodev2.h>
+#endif /* __NetBSD__ */
 #endif /* MOTION_V4L2 */
 #include <math.h>
 #include "motion.h"
