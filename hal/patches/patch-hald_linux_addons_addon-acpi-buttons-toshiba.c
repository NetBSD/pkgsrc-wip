$NetBSD$

--- hald/linux/addons/addon-acpi-buttons-toshiba.c.orig	2009-08-24 12:42:30.000000000 +0000
+++ hald/linux/addons/addon-acpi-buttons-toshiba.c
@@ -40,7 +40,7 @@ else
 #include <string.h>
 #include <unistd.h>
 
-#include <glib/gmain.h>
+#include <glib.h>
 
 #include "libhal/libhal.h"
 #include "../../logger.h"
