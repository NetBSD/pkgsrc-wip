$NetBSD$

--- readline/terminal.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ readline/terminal.c
@@ -32,6 +32,10 @@
 #  include <sys/file.h>
 #endif /* HAVE_SYS_FILE_H */
 
+#if defined (HAVE_SYS_IOCTL_H)
+#include <sys/ioctl.h>
+#endif /* HAVE_SYS_IOCTL_H */
+
 #if defined (HAVE_UNISTD_H)
 #  include <unistd.h>
 #endif /* HAVE_UNISTD_H */
