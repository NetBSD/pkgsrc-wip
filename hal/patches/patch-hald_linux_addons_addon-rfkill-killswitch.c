$NetBSD$

--- hald/linux/addons/addon-rfkill-killswitch.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-rfkill-killswitch.c
@@ -36,8 +36,6 @@
 #include <unistd.h> 
 
 #include <glib.h>
-#include <glib/gmain.h>
-#include <glib/gstdio.h>
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
