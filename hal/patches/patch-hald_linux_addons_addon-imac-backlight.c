$NetBSD$

--- hald/linux/addons/addon-imac-backlight.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-imac-backlight.c
@@ -29,7 +29,7 @@
 #include <stdlib.h>
 #include <sys/io.h>
 
-#include <glib/gmain.h>
+#include <glib.h>
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
