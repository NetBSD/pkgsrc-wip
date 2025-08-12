$NetBSD$

--- modules/javafx.graphics/src/main/native-glass/gtk/launcher.c.orig	2024-10-21 10:13:04.269805887 +0000
+++ modules/javafx.graphics/src/main/native-glass/gtk/launcher.c
@@ -25,7 +25,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#if defined(__linux__)
 #include <linux/fb.h>
+#endif
 #include <fcntl.h>
 #ifndef __USE_GNU       // required for dladdr() & Dl_info
 #define __USE_GNU
