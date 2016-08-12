$NetBSD$

--- src/VBox/Main/glue/NativeEventQueue.cpp.orig	2016-08-12 18:06:16.000000000 +0000
+++ src/VBox/Main/glue/NativeEventQueue.cpp
@@ -36,6 +36,10 @@
 # include <errno.h>
 #endif
 
+#ifdef RT_OS_NETBSD
+# include <sys/select.h>
+#endif
+
 namespace com
 {
 
