$NetBSD$

--- src/libide/core/ide-global.c.orig	2020-03-07 00:15:02.333880400 +0000
+++ src/libide/core/ide-global.c
@@ -26,7 +26,9 @@
 #include <glib/gi18n.h>
 #include <string.h>
 #include <sys/types.h>
+#ifndef __NetBSD__
 #include <sys/user.h>
+#endif
 #include <sys/utsname.h>
 #include <unistd.h>
 
