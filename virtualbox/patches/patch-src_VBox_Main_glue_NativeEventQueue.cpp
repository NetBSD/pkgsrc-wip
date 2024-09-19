$NetBSD$

--- src/VBox/Main/glue/NativeEventQueue.cpp.orig	2016-03-04 19:29:36.000000000 +0000
+++ src/VBox/Main/glue/NativeEventQueue.cpp
@@ -20,6 +20,11 @@
 
 #include <new> /* For bad_alloc. */
 
+#ifdef RT_OS_NETBSD
+#include <sys/select.h>
+#include <sys/time.h>
+#endif
+
 #ifdef RT_OS_DARWIN
 # include <CoreFoundation/CFRunLoop.h>
 #endif
