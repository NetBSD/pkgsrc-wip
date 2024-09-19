$NetBSD$

--- src/user.h.orig	2019-04-23 15:16:09.000000000 +0000
+++ src/user.h
@@ -22,7 +22,9 @@
 
 #include <sys/types.h>
 #include <pwd.h>
+#ifdef HAVE_SHADOW_H
 #include <shadow.h>
+#endif
 
 #include <glib.h>
 #include <gio/gio.h>
