$NetBSD$

--- hald/linux/addons/addon-omap-backlight.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-omap-backlight.c
@@ -41,7 +41,7 @@
 #include <fcntl.h>
 #include <unistd.h> 
 
-#include <glib/gmain.h>
+#include <glib.h>
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
