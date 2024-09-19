$NetBSD$

--- readline/terminal.c.orig	2017-09-11 11:24:05.000000000 +0000
+++ readline/terminal.c
@@ -28,6 +28,9 @@
 #include <sys/types.h>
 #include "posixstat.h"
 #include <fcntl.h>
+// #ifdef HAVE_SYS_IOCTL_H
+#include <sys/ioctl.h>
+// #endif
 #if defined (HAVE_SYS_FILE_H)
 #  include <sys/file.h>
 #endif /* HAVE_SYS_FILE_H */
