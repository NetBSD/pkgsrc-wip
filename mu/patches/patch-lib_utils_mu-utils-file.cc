$NetBSD$

--- lib/utils/mu-utils-file.cc.orig	2024-04-08 20:22:35.000000000 +0000
+++ lib/utils/mu-utils-file.cc
@@ -24,6 +24,10 @@
 
 #include <sys/stat.h>
 
+#if defined(__NetBSD__)
+#include <sys/wait.h>
+#endif
+
 #include <glib.h>
 #include <gio/gio.h>
 #include <gio/gunixinputstream.h>
