$NetBSD$

--- hald/linux/addons/addon-storage.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-storage.c
@@ -39,7 +39,7 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
-#include <glib/gmain.h>
+#include <glib.h>
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
