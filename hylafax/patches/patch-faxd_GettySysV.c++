$NetBSD: patch-faxd_GettySysV.c++,v 1.1 2012/04/10 10:26:19 ftigeot Exp $

--- faxd/GettySysV.c++.orig	2010-09-15 14:43:15.000000000 +0000
+++ faxd/GettySysV.c++
@@ -29,6 +29,10 @@
 #include <stddef.h>
 #include <termios.h>
 #include <sys/ioctl.h>
+#if defined(__DragonFly__)
+    #define HAS_UTMPX 1
+    #define HAS_EXIT_STATUS 1
+#endif
 extern "C" {
 #if HAS_UTMPX
 #if !HAS_EXIT_STATUS
