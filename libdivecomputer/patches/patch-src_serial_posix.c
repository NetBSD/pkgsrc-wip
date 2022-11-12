$NetBSD$

Check for another header where select(2) might be located.

--- src/serial_posix.c.orig	2021-05-07 12:23:36.000000000 -0700
+++ src/serial_posix.c	2022-11-11 23:11:32.355847371 -0800
@@ -33,6 +33,9 @@
 #ifdef HAVE_LINUX_SERIAL_H
 #include <linux/serial.h>
 #endif
+#ifdef HAVE_SYS_SELECT_H
+#include <sys/select.h>
+#endif
 #ifdef HAVE_IOKIT_SERIAL_IOSS_H
 #include <IOKit/serial/ioss.h>
 #endif
