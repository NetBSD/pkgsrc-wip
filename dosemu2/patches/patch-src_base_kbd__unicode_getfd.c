$NetBSD$

--- src/base/kbd_unicode/getfd.c.orig	2017-11-02 06:22:58.000000000 +0000
+++ src/base/kbd_unicode/getfd.c
@@ -11,7 +11,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#ifdef __linux__
 #include <sys/kd.h>
+#endif
 #include <sys/ioctl.h>
 #include "priv.h"
 #include "getfd.h"
