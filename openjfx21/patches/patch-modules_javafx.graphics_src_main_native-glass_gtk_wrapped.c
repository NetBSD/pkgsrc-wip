$NetBSD$

--- modules/javafx.graphics/src/main/native-glass/gtk/wrapped.c.orig	2024-10-21 10:32:44.512852512 +0000
+++ modules/javafx.graphics/src/main/native-glass/gtk/wrapped.c
@@ -24,7 +24,9 @@
  */
 
 #include <stdio.h>
+#if defined(__linux__)
 #include <linux/fb.h>
+#endif
 #include <fcntl.h>
 #ifndef __USE_GNU       // required for dladdr() & Dl_info
 #define __USE_GNU
