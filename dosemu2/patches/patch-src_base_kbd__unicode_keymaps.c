$NetBSD$

--- src/base/kbd_unicode/keymaps.c.orig	2017-11-02 06:22:58.000000000 +0000
+++ src/base/kbd_unicode/keymaps.c
@@ -10,8 +10,10 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef __linux
 #include <sys/kd.h>
 #include <linux/keyboard.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
