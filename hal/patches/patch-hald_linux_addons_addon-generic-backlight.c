$NetBSD$

--- hald/linux/addons/addon-generic-backlight.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-generic-backlight.c
@@ -35,7 +35,7 @@
 #include <sys/stat.h>
 #include <unistd.h> 
 
-#include <glib/gmain.h>
+#include <glib.h>
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
