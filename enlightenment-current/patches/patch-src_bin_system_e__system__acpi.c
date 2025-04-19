$NetBSD$

--- src/bin/system/e_system_acpi.c.orig	2025-02-08 14:04:44.419871685 +0000
+++ src/bin/system/e_system_acpi.c
@@ -3,6 +3,8 @@
 // no local funcs
 #elif defined __FreeBSD__
 // no local funcs
+#elif defined __NetBSD__
+// no local funcs
 #else
 #  include <linux/input.h>
 #  include <fcntl.h>
@@ -234,6 +236,8 @@ e_system_acpi_init(void)
 // no local funcs
 #  elif defined __FreeBSD__
 // no local funcs
+#  elif defined __NetBSD__
+// no local funcs
 #  else
   dev_open();
 #endif
