$NetBSD$

--- hald/freebsd/hf-ata.c.orig	2008-08-10 13:50:10.000000000 +0000
+++ hald/freebsd/hf-ata.c
@@ -30,7 +30,11 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/ioctl.h>
+#ifdef __DragonFly__
+#include <sys/nata.h>
+#else
 #include <sys/ata.h>
+#endif
 
 #include "../logger.h"
 
