$NetBSD$

--- readline/rltty.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ readline/rltty.c
@@ -37,9 +37,9 @@
 
 #include "rldefs.h"
 
-#if defined (GWINSZ_IN_SYS_IOCTL)
+#if defined (HAVE_SYS_IOCTL_H)
 #  include <sys/ioctl.h>
-#endif /* GWINSZ_IN_SYS_IOCTL */
+#endif /* HAVE_SYS_IOCTL_H */
 
 #include "rltty.h"
 #include "readline.h"
