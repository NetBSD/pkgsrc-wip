$NetBSD$

--- hald/linux/addons/addon-input.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-input.c
@@ -41,8 +41,7 @@
 #else
   #include <linux/input.h>
 #endif
-#include <glib/gmain.h>
-#include <glib/gprintf.h>
+#include <glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
 #include "libhal/libhal.h"
