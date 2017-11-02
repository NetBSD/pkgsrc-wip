$NetBSD$

--- src/base/kbd_unicode/keyb_raw.c.orig	2017-11-02 06:22:58.000000000 +0000
+++ src/base/kbd_unicode/keyb_raw.c
@@ -9,7 +9,9 @@
 #include <errno.h>
 #include <string.h>
 #include <sys/stat.h>
+#ifdef __linux__
 #include <sys/kd.h>
+#endif
 #include <sys/ioctl.h>
 
 #include "emu.h"
