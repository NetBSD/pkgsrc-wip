$NetBSD$

--- server/red-stream.cpp.orig	2023-05-12 08:37:06.000000000 +0000
+++ server/red-stream.cpp
@@ -17,6 +17,15 @@
 */
 #include <config.h>
 
+#if defined(__sun)
+#define MSG_NOSIGNAL   0
+#  if __STDC_VERSION__ - 0 < 199901L
+#define _XOPEN_SOURCE  500
+#  else
+#define _XOPEN_SOURCE  600
+#  endif
+#endif
+
 #include <cerrno>
 
 #include <fcntl.h>
