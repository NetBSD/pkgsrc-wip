$NetBSD$

--- src/base/dev/misc/timers.c.orig	2017-11-02 06:22:58.000000000 +0000
+++ src/base/dev/misc/timers.c
@@ -29,7 +29,9 @@
  */
 
 #include <sys/time.h>
+#ifdef __linux__
 #include <sys/kd.h>
+#endif
 #include <sys/ioctl.h>
 #include "config.h"
 #include "emu.h"
